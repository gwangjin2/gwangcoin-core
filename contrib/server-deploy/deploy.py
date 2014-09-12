#!/usr/bin/env python
import os

# aws.amazon.server ip list
HOSTS=[
'54.92.117.108', 	# don1 
'54.92.83.57',		# don2
'54.92.118.14',  	# don3
'54.64.41.133',  	# don4
'54.64.66.148',  	# don5
'54.64.15.133',  	# don6
'54.64.119.142'  	# don7
]

FILES = [
'suwoncoind',
'suwoncoin.conf',
'clean_suwoncoin.sh',
'start_suwoncoin.sh',
'stop_suwoncoin.sh',
'backup_suwoncoin.sh',
]

for host in HOSTS:
	for fn in FILES:
		cmd = 'scp -i ~/suwon_amazon_key.pem %s ubuntu@%s:%s' % (fn,host,fn)
		print cmd
		os.system(cmd)
