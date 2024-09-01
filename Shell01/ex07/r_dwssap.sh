cat /etc/passwd | grep -G '.*:x:' -o | sed -n '1~2p' | sort -dr | sed -n ${FT_LINE1},${FT_LINE2}p | sed -e 's/\:x:\+/, /g' | tr -d '\r' | tr -d '\n'| sed 's/,.$/./'
