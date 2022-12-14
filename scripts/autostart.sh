#!/bin/bash

bash -c '~/suckless/scripts/tap-to-click.sh &'
bash -c '~/suckless/scripts/inverse-scroll.sh &'
bash -c '~/suckless/scripts/wp-change.sh &'
bash -c '~/suckless/dwm/scripts/dwm-status.sh &'
#bash -c  '~/suckless/scripts/dynamic_wallpaper.sh &'

arr=("pnmixer" "copyq" "nm-applet" "picom -b" "fcitx5")

for value in ${arr[@]}; do
    isExist=$(ps -ef | grep $value | grep -v grep | wc -l)
    if [ $isExist = 0 ]; then
        exec $value &
    fi
done
