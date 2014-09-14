#! /bin/sh

check_config() {
    if [ ! -e /etc/ssh/sshd_not_to_be_run ]; then
	/usr/sbin/sshd $SSHD_OPTS -t || exit 1
    fi
}


case "$1" in
  start)
	
	;;
  stop)

	check_for_upstart 0
	log_daemon_msg "Stopping OpenBSD Secure Shell server" "sshd" || true
	if start-stop-daemon --stop --quiet --oknodo --pidfile /var/run/sshd.pid; then
	    log_end_msg 0 || true
	else
	    log_end_msg 1 || true
	fi
	;;


  status)
	check_for_upstart 1
	status_of_proc -p /var/run/sshd.pid /usr/sbin/sshd sshd && exit 0 || exit $?
	;;

  *)
	log_action_msg "Usage: suwoncoin.sh {start|stop|clean|backup|status}" || true
	exit 1
esac

exit 0
