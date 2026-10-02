#!/bin/sh
echo "=== Machine ==="
echo "OS : $(. /etc/os-release && echo "$PRETTY_NAME") ($(uname -m))"
echo "CPU : $(lscpu | grep 'Model name' | sed 's/.*: *//')"
cores=$(lscpu | awk '/^Core\(s\) per socket/ {print $NF}')
sockets=$(lscpu | awk '/^Socket\(s\)/ {print $NF}')
echo "Cœurs physiques : $((cores * sockets))"
echo "Processeurs logiques : $(nproc)"
echo "RAM : $(free -h | awk '/Mem:/ {print $2}')"
maxmhz=$(lscpu | awk -F: '/CPU max MHz/ {gsub(/ /,"",$2); print $2}')
echo "Fréquence max : ${maxmhz:-non accessible} MHz"
echo "Compilateur : $(c++ --version | head -n1)"
echo "Virtualisation : $(systemd-detect-virt 2>/dev/null || echo inconnue)"
