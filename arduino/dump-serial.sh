#! /bin/sh

# Dump the serial line data from Arduno controller, with metadata
# (time, date, controller)

set -ue

if [ $# -gt 0 ]
then
    TTY="$1"
else
    TTY=/dev/ttyACM0
fi

lsusb | grep -i arduino | awk '{print "#", $0}'

perl -e \
     'BEGIN {$| = 1; open(TTY,$ARGV[0]) or die $!}
      for(;;) { sysread(TTY,$data,512); print $data}' \
     $TTY \
| while read LINE
do
    echo $(date +"%F %H:%M:%S") $LINE
done
