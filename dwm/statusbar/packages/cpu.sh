#! /bin/bash
# CPU 获取CPU使用率和温度的脚本

tempfile=$(cd $(dirname $0);cd ..;pwd)/temp

this=_cpu
icon_color="^c#3E206F^^b#CCCCFF0x88^"
text_color="^c#3E206F^^b#CCCCFF0x99^"
signal=$(echo "^s$this^" | sed 's/_//')

update() {
    cpu_icon="󰻠"
    cpu_text=$(top -bn 1 | grep '^%Cpu' | tr -d 'usy,' | awk '{print $2 }')
    temp_text=$(tlp-stat -t | grep CPU |awk '{print $4}')

    icon=" $cpu_icon"
    text=" $cpu_text% $temp_text°C "

    sed -i '/^export '$this'=.*$/d' $tempfile
    printf "export %s='%s%s%s%s%s'\n" $this "$signal" "$icon_color" "$icon" "$text_color" "$text" >> $tempfile
}

notify() {
    notify-send "󰻠 CPU tops" "\n$(ps axch -o cmd:15,%cpu --sort=-%cpu | head)\\n\\n(100% per core)" -r 9527
}

call_btop() {
    pid1=`ps aux | grep 'st -t statusutil' | grep -v grep | awk '{print $2}'`
    pid2=`ps aux | grep 'st -t statusutil_cpu' | grep -v grep | awk '{print $2}'`
    mx=`xdotool getmouselocation --shell | grep X= | sed 's/X=//'`
    my=`xdotool getmouselocation --shell | grep Y= | sed 's/Y=//'`
    kill $pid1 && kill $pid2 || st -t statusutil_cpu -g 82x25+$((mx - 328))+$((my + 20)) -c FGN -e btop
}

click() {
    case "$1" in
        L) notify ;;
        M) ;;
        R) call_btop ;;
        U) ;;
        D) ;;
    esac
}

case "$1" in
    click) click $2 ;;
    notify) notify ;;
    *) update ;;
esac
