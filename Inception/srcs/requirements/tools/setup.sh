#!/bin/bash

URL="127.0.0.1 donpark.42.fr"
RESULT=$(cat /etc/hosts | grep "$URL" | wc -l)

if [ $RESULT -eq 0 ]; then
    sudo chmod 777 /etc/hosts
    sudo echo "$URL" >> /etc/hosts
fi
mkdir -p $HOME/data/db_data $HOME/data/wp_data