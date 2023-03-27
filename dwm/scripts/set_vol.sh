#! /bin/bash


case $1 in
    up) /usr/bin/amixer set Master 5%+ unmute ;;
    down) /usr/bin/amixer set Master 5%- unmute ;;
    toggle) /usr/bin/amixer set Master toggle ;;
esac

bash $DWM/statusbar/statusbar.sh update vol
bash $DWM/statusbar/packages/vol.sh notify 
