id -Gn ${FT_USER} | sed -e 's/\s\+/,/g' | tr -d '\r' | tr -d '\n'
