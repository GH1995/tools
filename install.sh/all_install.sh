#!/bin/bash
# Author: GH1995

source ./install_software.sh
source ./uninstall.sh

# ------------------------------------------------------------+
# 可选的一些工具和配置                                        |
#                                                             |
# 中文文档[已过时]                                            |
# sudo apt install manpages-zh -y                             |
#                                                             |
# spacemacs的配置                                             |
# git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d  |
#                                                             |
# ------------------------------------------------------------+


# upgrade
source ~/.bashrc && sudo apt upgrade -y
if [ $? -eq 0]
then
    echo "EVERYTHING IS OK!" >> install_log.txt;
fi

# --------------------------------------------------------------------------
exit
