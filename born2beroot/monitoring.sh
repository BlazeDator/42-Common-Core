#!/bin/sh

architecture=$(uname -a)

cpu_cores=$(grep "cpu cores" /proc/cpuinfo -m 1 | awk '{print $4}')
cpu_threads=$(grep "siblings" /proc/cpuinfo -m 1 | awk '{print $3}')
top -b -n 1 > /tmp/top_output.txt
cpu_load=$(cat /tmp/top_output.txt | tail +8 | awk '{cpu += $9} END {print cpu}')
#cpu_load=$(ps -o %cpu --no-headers | awk '{cpul += $1} END {print cpul}')
#cpu_load=$(ps -o %cpu --no-headers | awk '{cpul += $1} END {print cpul}')

used_ram=$(free --mega | grep "Mem" | awk '{print $3}')
max_ram=$(free --mega | grep "Mem" | awk '{print $2}')
perc_ram=$(awk -v used_ram=$used_ram -v max_ram=$max_ram \
'BEGIN { printf "%.2f", used_ram * 100 / max_ram; }')

used_disk=$(df -BM | grep "/dev/" | grep -v "/boot" | awk '{disk += $3} END {print disk}')
max_disk=$(df -BG | grep "/dev/" | grep -v "/boot" | awk '{disk += $2} END {print disk}')
perc_disk=$(df -BM | grep "/dev/" | grep -v "/boot" | \
awk '{disk_u += $3} {disk_m += $2} END {printf "%d", disk_u * 100 / disk_m}')

last_boot=$(who -b | grep -o -E "[0-9].*$")

lvm=$(lsblk | tail +2 | awk {'print $6'} | grep "lvm" | wc -l)

if [ "$lvm" -gt 0 ]; then
	lvm="yes"
else
	lvm="no"
fi

tcp=$(ss -ta | grep "ESTAB" | wc -l)

users=$(users | wc -w)

ip=$(hostname -I)
MAC=$(ip link | grep "link/ether" | awk '{print $2}')

sudo=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

echo "	#Architecture: $architecture
	#CPU physical : $cpu_cores
	#vCPU : $cpu_threads
	#Memory Usage: $used_ram/${max_ram}MB (${perc_ram}%)
	#Disk Usage: $used_disk/${max_disk}Gb (${perc_disk}%)
	#CPU load: $cpu_load%
	#Last boot: $last_boot
	#LVM use: $lvm
	#Connections TCP : $tcp ESTABLISHED
	#User log: $users
	#Network: IP $ip($MAC)
	#Sudo : $sudo cmd"
