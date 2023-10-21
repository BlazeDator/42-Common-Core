#!/bin/sh

architecture=$(uname -a)

cpu_cores=$(grep "cpu cores" /proc/cpuinfo -m 1 | awk '{print $4}')
cpu_threads=$(grep "siblings" /proc/cpuinfo -m 1 | awk '{print $3}')

perc=100

used_ram=$(free --mega | grep "Mem" | awk '{print $3}')
max_ram=$(free --mega | grep "Mem" | awk '{print $2}')
perc_ram=$(awk -v used_ram="$used_ram" -v perc=$perc -v max_ram=$max_ram \
'BEGIN{ printf "%.2f", used_ram * perc / max_ram;}')

used_disk=0
max_disk=0
perc_disk=0

echo "	#Architecture: $architecture
	#CPU physical : $cpu_cores
	#vCPU : $cpu_threads
	#Memory Usage: $used_ram/${max_ram}MB (${perc_ram}%)"
