#! /bin/sh

check_config() {
    if [ ! -e /etc/ssh/sshd_not_to_be_run ]; then
	/usr/sbin/sshd $SSHD_OPTS -t || exit 1
    fi
}


case "$1" in
  start)
	echo 'restart suwoncoind...'
	./suwoncoind -daemon
	ps ax |grep suwoncoind	
	;;
  stop)

	echo 'kill suwoncond...'
	pkill -9 suwoncoind
	;;


  status)
	ps ax |grep suwoncoind
	;;

  *)
	echo "Usage: suwoncoin.sh {start|stop|clean|backup|status}" || true
	exit 1
esac

exit 0
