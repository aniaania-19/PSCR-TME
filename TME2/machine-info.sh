#!/usr/bin/env bash
# Usage : ./machine-info.sh [dossier-de-build]   (défaut : build)
export LC_ALL=C
b=${1:-build}
echo '## Machine de mesure'; echo; echo '```text'
echo "OS : $(. /etc/os-release && echo "$PRETTY_NAME") ($(uname -srm))"
echo "CPU : $(lscpu | awk -F: '/^Model name/ {gsub(/^ +/,"",$2); print $2}')"
echo "Cœurs par socket : $(lscpu | awk '/^Core\(s\) per socket/ {print $NF}') x $(lscpu | awk '/^Socket\(s\)/ {print $NF}') socket(s)"
echo "Processeurs logiques : $(nproc)"
echo "RAM : $(free -h | awk '/Mem:/ {print $2}')"
echo "Fréquence max (MHz) : $(lscpu | awk -F: '/CPU max MHz/ {gsub(/ /,"",$2); print $2}' | grep . || echo non exposée)"
echo "Compilateur (c++) : $(c++ --version | head -n1)"
echo "Compilateur CMake : $(grep CMAKE_CXX_COMPILER: $b/CMakeCache.txt 2>/dev/null | cut -d= -f2)"
echo "Type de build : $(grep CMAKE_BUILD_TYPE: $b/CMakeCache.txt 2>/dev/null | cut -d= -f2)"
echo "Virtualisation : $(systemd-detect-virt 2>/dev/null || echo inconnue) (none = native)"
echo "Charge : $(cut -d' ' -f1-3 /proc/loadavg)"
echo '```'
