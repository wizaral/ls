cp ../LS/uls .

zsh compare.sh <(ls -nisTOGfFqh@e 2>&1) <(./uls -nisTOGfFqh@e 2>&1) "-nisTOGfFqh@e"
zsh compare.sh <(ls -AF@eGisTOnh Makefile ../Makefile / /dev /dev/fd /tmp/ 2>&1) <(./uls -AF@eGisTOnh Makefile ../Makefile / /dev /dev/fd /tmp/ 2>&1) "-AF@eGisTOnh Makefile ../Makefile / /dev /dev/fd /tmp/"
zsh compare.sh <(ls -privet 2>&1) <(./uls -privet 2>&1) "-privet"
zsh compare.sh <(ls -1FiSra / 2>&1) <(./uls -1FiSra / 2>&1) "-1FiSra /"

zsh compare.sh <(ls -Aa 2>&1) <(./uls -Aa 2>&1) "-Aa"
zsh compare.sh <(ls -aA 2>&1) <(./uls -aA 2>&1) "-aA"

zsh compare.sh <(ls -Aaf 2>&1) <(./uls -Aaf 2>&1) "-Aaf"
zsh compare.sh <(ls -Afa 2>&1) <(./uls -Afa 2>&1) "-Afa"
zsh compare.sh <(ls -aAf 2>&1) <(./uls -aAf 2>&1) "-aAf"
zsh compare.sh <(ls -afA 2>&1) <(./uls -afA 2>&1) "-afA"
zsh compare.sh <(ls -fAa 2>&1) <(./uls -fAa 2>&1) "-fAa"
zsh compare.sh <(ls -faA 2>&1) <(./uls -faA 2>&1) "-faA"

zsh compare.sh <(ls -qvw 2>&1) <(./uls -qvw 2>&1) "-qvw"
zsh compare.sh <(ls -qwv 2>&1) <(./uls -qwv 2>&1) "-qwv"
zsh compare.sh <(ls -vqw 2>&1) <(./uls -vqw 2>&1) "-vqw"
zsh compare.sh <(ls -vwq 2>&1) <(./uls -vwq 2>&1) "-vwq"
zsh compare.sh <(ls -wqv 2>&1) <(./uls -wqv 2>&1) "-wqv"
zsh compare.sh <(ls -wvq 2>&1) <(./uls -wvq 2>&1) "-wvq"

zsh compare.sh <(ls -Fp 2>&1) <(./uls -Fp 2>&1) "-Fp"
zsh compare.sh <(ls -pF 2>&1) <(./uls -pF 2>&1) "-pF"

zsh compare.sh <(ls -l 2>&1) <(./uls -l 2>&1) "-l"
zsh compare.sh <(ls -lUcu 2>&1) <(./uls -lUcu 2>&1) "-lUcu"
zsh compare.sh <(ls -lUuc 2>&1) <(./uls -lUuc 2>&1) "-lUuc"
zsh compare.sh <(ls -lcUu 2>&1) <(./uls -lcUu 2>&1) "-lcUu"
zsh compare.sh <(ls -lcuU 2>&1) <(./uls -lcuU 2>&1) "-lcuU"
zsh compare.sh <(ls -luUc 2>&1) <(./uls -luUc 2>&1) "-luUc"
zsh compare.sh <(ls -lucU 2>&1) <(./uls -lucU 2>&1) "-lucU"

zsh compare.sh <(ls -t 2>&1) <(./uls -t 2>&1) "-t"
zsh compare.sh <(ls -tUcu 2>&1) <(./uls -tUcu 2>&1) "-tUcu"
zsh compare.sh <(ls -tUuc 2>&1) <(./uls -tUuc 2>&1) "-tUuc"
zsh compare.sh <(ls -tcUu 2>&1) <(./uls -tcUu 2>&1) "-tcUu"
zsh compare.sh <(ls -tcuU 2>&1) <(./uls -tcuU 2>&1) "-tcuU"
zsh compare.sh <(ls -tuUc 2>&1) <(./uls -tuUc 2>&1) "-tuUc"
zsh compare.sh <(ls -tucU 2>&1) <(./uls -tucU 2>&1) "-tucU"

zsh compare.sh <(ls -Sfrt 2>&1) <(./uls -Sfrt 2>&1) "-Sfrt"
zsh compare.sh <(ls -Sftr 2>&1) <(./uls -Sftr 2>&1) "-Sftr"
zsh compare.sh <(ls -Srft 2>&1) <(./uls -Srft 2>&1) "-Srft"
zsh compare.sh <(ls -Srtf 2>&1) <(./uls -Srtf 2>&1) "-Srtf"
zsh compare.sh <(ls -Stfr 2>&1) <(./uls -Stfr 2>&1) "-Stfr"
zsh compare.sh <(ls -Strf 2>&1) <(./uls -Strf 2>&1) "-Strf"
zsh compare.sh <(ls -fSrt 2>&1) <(./uls -fSrt 2>&1) "-fSrt"
zsh compare.sh <(ls -fStr 2>&1) <(./uls -fStr 2>&1) "-fStr"
zsh compare.sh <(ls -frSt 2>&1) <(./uls -frSt 2>&1) "-frSt"
zsh compare.sh <(ls -frtS 2>&1) <(./uls -frtS 2>&1) "-frtS"
zsh compare.sh <(ls -ftSr 2>&1) <(./uls -ftSr 2>&1) "-ftSr"
zsh compare.sh <(ls -ftrS 2>&1) <(./uls -ftrS 2>&1) "-ftrS"
zsh compare.sh <(ls -rSft 2>&1) <(./uls -rSft 2>&1) "-rSft"
zsh compare.sh <(ls -rStf 2>&1) <(./uls -rStf 2>&1) "-rStf"
zsh compare.sh <(ls -rfSt 2>&1) <(./uls -rfSt 2>&1) "-rfSt"
zsh compare.sh <(ls -rftS 2>&1) <(./uls -rftS 2>&1) "-rftS"
zsh compare.sh <(ls -rtSf 2>&1) <(./uls -rtSf 2>&1) "-rtSf"
zsh compare.sh <(ls -rtfS 2>&1) <(./uls -rtfS 2>&1) "-rtfS"
zsh compare.sh <(ls -tSfr 2>&1) <(./uls -tSfr 2>&1) "-tSfr"
zsh compare.sh <(ls -tSrf 2>&1) <(./uls -tSrf 2>&1) "-tSrf"
zsh compare.sh <(ls -tfSr 2>&1) <(./uls -tfSr 2>&1) "-tfSr"
zsh compare.sh <(ls -tfrS 2>&1) <(./uls -tfrS 2>&1) "-tfrS"
zsh compare.sh <(ls -trSf 2>&1) <(./uls -trSf 2>&1) "-trSf"
zsh compare.sh <(ls -trfS 2>&1) <(./uls -trfS 2>&1) "-trfS"

zsh compare.sh <(ls -Sft 2>&1) <(./uls -Sft 2>&1) "-Sft"
zsh compare.sh <(ls -Stf 2>&1) <(./uls -Stf 2>&1) "-Stf"
zsh compare.sh <(ls -fSt 2>&1) <(./uls -fSt 2>&1) "-fSt"
zsh compare.sh <(ls -ftS 2>&1) <(./uls -ftS 2>&1) "-ftS"
zsh compare.sh <(ls -tSf 2>&1) <(./uls -tSf 2>&1) "-tSf"
zsh compare.sh <(ls -tfS 2>&1) <(./uls -tfS 2>&1) "-tfS"

zsh compare.sh <(ls -Srt 2>&1) <(./uls -Srt 2>&1) "-Srt"
zsh compare.sh <(ls -Str 2>&1) <(./uls -Str 2>&1) "-Str"
zsh compare.sh <(ls -rSt 2>&1) <(./uls -rSt 2>&1) "-rSt"
zsh compare.sh <(ls -rtS 2>&1) <(./uls -rtS 2>&1) "-rtS"
zsh compare.sh <(ls -tSr 2>&1) <(./uls -tSr 2>&1) "-tSr"
zsh compare.sh <(ls -trS 2>&1) <(./uls -trS 2>&1) "-trS"

zsh compare.sh <(ls -St 2>&1) <(./uls -St 2>&1) "-St"
zsh compare.sh <(ls -tS 2>&1) <(./uls -tS 2>&1) "-tS"

zsh compare.sh <(ls -l@e 2>&1) <(./uls -l@e 2>&1) "-l@e"
zsh compare.sh <(ls -le@ 2>&1) <(./uls -le@ 2>&1) "-le@"

zsh compare.sh <(ls -gn 2>&1) <(./uls -gn 2>&1) "-gn"
zsh compare.sh <(ls -ng 2>&1) <(./uls -ng 2>&1) "-ng"

zsh compare.sh <(ls -1Clmx 2>&1) <(./uls -1Clmx 2>&1) "-1Clmx"
zsh compare.sh <(ls -1Clxm 2>&1) <(./uls -1Clxm 2>&1) "-1Clxm"
zsh compare.sh <(ls -1Cmlx 2>&1) <(./uls -1Cmlx 2>&1) "-1Cmlx"
zsh compare.sh <(ls -1Cmxl 2>&1) <(./uls -1Cmxl 2>&1) "-1Cmxl"
zsh compare.sh <(ls -1Cxlm 2>&1) <(./uls -1Cxlm 2>&1) "-1Cxlm"
zsh compare.sh <(ls -1Cxml 2>&1) <(./uls -1Cxml 2>&1) "-1Cxml"
zsh compare.sh <(ls -1lCmx 2>&1) <(./uls -1lCmx 2>&1) "-1lCmx"
zsh compare.sh <(ls -1lCxm 2>&1) <(./uls -1lCxm 2>&1) "-1lCxm"
zsh compare.sh <(ls -1lmCx 2>&1) <(./uls -1lmCx 2>&1) "-1lmCx"
zsh compare.sh <(ls -1lmxC 2>&1) <(./uls -1lmxC 2>&1) "-1lmxC"
zsh compare.sh <(ls -1lxCm 2>&1) <(./uls -1lxCm 2>&1) "-1lxCm"
zsh compare.sh <(ls -1lxmC 2>&1) <(./uls -1lxmC 2>&1) "-1lxmC"
zsh compare.sh <(ls -1mClx 2>&1) <(./uls -1mClx 2>&1) "-1mClx"
zsh compare.sh <(ls -1mCxl 2>&1) <(./uls -1mCxl 2>&1) "-1mCxl"
zsh compare.sh <(ls -1mlCx 2>&1) <(./uls -1mlCx 2>&1) "-1mlCx"
zsh compare.sh <(ls -1mlxC 2>&1) <(./uls -1mlxC 2>&1) "-1mlxC"
zsh compare.sh <(ls -1mxCl 2>&1) <(./uls -1mxCl 2>&1) "-1mxCl"
zsh compare.sh <(ls -1mxlC 2>&1) <(./uls -1mxlC 2>&1) "-1mxlC"
zsh compare.sh <(ls -1xClm 2>&1) <(./uls -1xClm 2>&1) "-1xClm"
zsh compare.sh <(ls -1xCml 2>&1) <(./uls -1xCml 2>&1) "-1xCml"
zsh compare.sh <(ls -1xlCm 2>&1) <(./uls -1xlCm 2>&1) "-1xlCm"
zsh compare.sh <(ls -1xlmC 2>&1) <(./uls -1xlmC 2>&1) "-1xlmC"
zsh compare.sh <(ls -1xmCl 2>&1) <(./uls -1xmCl 2>&1) "-1xmCl"
zsh compare.sh <(ls -1xmlC 2>&1) <(./uls -1xmlC 2>&1) "-1xmlC"
zsh compare.sh <(ls -C1lmx 2>&1) <(./uls -C1lmx 2>&1) "-C1lmx"
zsh compare.sh <(ls -C1lxm 2>&1) <(./uls -C1lxm 2>&1) "-C1lxm"
zsh compare.sh <(ls -C1mlx 2>&1) <(./uls -C1mlx 2>&1) "-C1mlx"
zsh compare.sh <(ls -C1mxl 2>&1) <(./uls -C1mxl 2>&1) "-C1mxl"
zsh compare.sh <(ls -C1xlm 2>&1) <(./uls -C1xlm 2>&1) "-C1xlm"
zsh compare.sh <(ls -C1xml 2>&1) <(./uls -C1xml 2>&1) "-C1xml"
zsh compare.sh <(ls -Cl1mx 2>&1) <(./uls -Cl1mx 2>&1) "-Cl1mx"
zsh compare.sh <(ls -Cl1xm 2>&1) <(./uls -Cl1xm 2>&1) "-Cl1xm"
zsh compare.sh <(ls -Clm1x 2>&1) <(./uls -Clm1x 2>&1) "-Clm1x"
zsh compare.sh <(ls -Clmx1 2>&1) <(./uls -Clmx1 2>&1) "-Clmx1"
zsh compare.sh <(ls -Clx1m 2>&1) <(./uls -Clx1m 2>&1) "-Clx1m"
zsh compare.sh <(ls -Clxm1 2>&1) <(./uls -Clxm1 2>&1) "-Clxm1"
zsh compare.sh <(ls -Cm1lx 2>&1) <(./uls -Cm1lx 2>&1) "-Cm1lx"
zsh compare.sh <(ls -Cm1xl 2>&1) <(./uls -Cm1xl 2>&1) "-Cm1xl"
zsh compare.sh <(ls -Cml1x 2>&1) <(./uls -Cml1x 2>&1) "-Cml1x"
zsh compare.sh <(ls -Cmlx1 2>&1) <(./uls -Cmlx1 2>&1) "-Cmlx1"
zsh compare.sh <(ls -Cmx1l 2>&1) <(./uls -Cmx1l 2>&1) "-Cmx1l"
zsh compare.sh <(ls -Cmxl1 2>&1) <(./uls -Cmxl1 2>&1) "-Cmxl1"
zsh compare.sh <(ls -Cx1lm 2>&1) <(./uls -Cx1lm 2>&1) "-Cx1lm"
zsh compare.sh <(ls -Cx1ml 2>&1) <(./uls -Cx1ml 2>&1) "-Cx1ml"
zsh compare.sh <(ls -Cxl1m 2>&1) <(./uls -Cxl1m 2>&1) "-Cxl1m"
zsh compare.sh <(ls -Cxlm1 2>&1) <(./uls -Cxlm1 2>&1) "-Cxlm1"
zsh compare.sh <(ls -Cxm1l 2>&1) <(./uls -Cxm1l 2>&1) "-Cxm1l"
zsh compare.sh <(ls -Cxml1 2>&1) <(./uls -Cxml1 2>&1) "-Cxml1"
zsh compare.sh <(ls -l1Cmx 2>&1) <(./uls -l1Cmx 2>&1) "-l1Cmx"
zsh compare.sh <(ls -l1Cxm 2>&1) <(./uls -l1Cxm 2>&1) "-l1Cxm"
zsh compare.sh <(ls -l1mCx 2>&1) <(./uls -l1mCx 2>&1) "-l1mCx"
zsh compare.sh <(ls -l1mxC 2>&1) <(./uls -l1mxC 2>&1) "-l1mxC"
zsh compare.sh <(ls -l1xCm 2>&1) <(./uls -l1xCm 2>&1) "-l1xCm"
zsh compare.sh <(ls -l1xmC 2>&1) <(./uls -l1xmC 2>&1) "-l1xmC"
zsh compare.sh <(ls -lC1mx 2>&1) <(./uls -lC1mx 2>&1) "-lC1mx"
zsh compare.sh <(ls -lC1xm 2>&1) <(./uls -lC1xm 2>&1) "-lC1xm"
zsh compare.sh <(ls -lCm1x 2>&1) <(./uls -lCm1x 2>&1) "-lCm1x"
zsh compare.sh <(ls -lCmx1 2>&1) <(./uls -lCmx1 2>&1) "-lCmx1"
zsh compare.sh <(ls -lCx1m 2>&1) <(./uls -lCx1m 2>&1) "-lCx1m"
zsh compare.sh <(ls -lCxm1 2>&1) <(./uls -lCxm1 2>&1) "-lCxm1"
zsh compare.sh <(ls -lm1Cx 2>&1) <(./uls -lm1Cx 2>&1) "-lm1Cx"
zsh compare.sh <(ls -lm1xC 2>&1) <(./uls -lm1xC 2>&1) "-lm1xC"
zsh compare.sh <(ls -lmC1x 2>&1) <(./uls -lmC1x 2>&1) "-lmC1x"
zsh compare.sh <(ls -lmCx1 2>&1) <(./uls -lmCx1 2>&1) "-lmCx1"
zsh compare.sh <(ls -lmx1C 2>&1) <(./uls -lmx1C 2>&1) "-lmx1C"
zsh compare.sh <(ls -lmxC1 2>&1) <(./uls -lmxC1 2>&1) "-lmxC1"
zsh compare.sh <(ls -lx1Cm 2>&1) <(./uls -lx1Cm 2>&1) "-lx1Cm"
zsh compare.sh <(ls -lx1mC 2>&1) <(./uls -lx1mC 2>&1) "-lx1mC"
zsh compare.sh <(ls -lxC1m 2>&1) <(./uls -lxC1m 2>&1) "-lxC1m"
zsh compare.sh <(ls -lxCm1 2>&1) <(./uls -lxCm1 2>&1) "-lxCm1"
zsh compare.sh <(ls -lxm1C 2>&1) <(./uls -lxm1C 2>&1) "-lxm1C"
zsh compare.sh <(ls -lxmC1 2>&1) <(./uls -lxmC1 2>&1) "-lxmC1"
zsh compare.sh <(ls -m1Clx 2>&1) <(./uls -m1Clx 2>&1) "-m1Clx"
zsh compare.sh <(ls -m1Cxl 2>&1) <(./uls -m1Cxl 2>&1) "-m1Cxl"
zsh compare.sh <(ls -m1lCx 2>&1) <(./uls -m1lCx 2>&1) "-m1lCx"
zsh compare.sh <(ls -m1lxC 2>&1) <(./uls -m1lxC 2>&1) "-m1lxC"
zsh compare.sh <(ls -m1xCl 2>&1) <(./uls -m1xCl 2>&1) "-m1xCl"
zsh compare.sh <(ls -m1xlC 2>&1) <(./uls -m1xlC 2>&1) "-m1xlC"
zsh compare.sh <(ls -mC1lx 2>&1) <(./uls -mC1lx 2>&1) "-mC1lx"
zsh compare.sh <(ls -mC1xl 2>&1) <(./uls -mC1xl 2>&1) "-mC1xl"
zsh compare.sh <(ls -mCl1x 2>&1) <(./uls -mCl1x 2>&1) "-mCl1x"
zsh compare.sh <(ls -mClx1 2>&1) <(./uls -mClx1 2>&1) "-mClx1"
zsh compare.sh <(ls -mCx1l 2>&1) <(./uls -mCx1l 2>&1) "-mCx1l"
zsh compare.sh <(ls -mCxl1 2>&1) <(./uls -mCxl1 2>&1) "-mCxl1"
zsh compare.sh <(ls -ml1Cx 2>&1) <(./uls -ml1Cx 2>&1) "-ml1Cx"
zsh compare.sh <(ls -ml1xC 2>&1) <(./uls -ml1xC 2>&1) "-ml1xC"
zsh compare.sh <(ls -mlC1x 2>&1) <(./uls -mlC1x 2>&1) "-mlC1x"
zsh compare.sh <(ls -mlCx1 2>&1) <(./uls -mlCx1 2>&1) "-mlCx1"
zsh compare.sh <(ls -mlx1C 2>&1) <(./uls -mlx1C 2>&1) "-mlx1C"
zsh compare.sh <(ls -mlxC1 2>&1) <(./uls -mlxC1 2>&1) "-mlxC1"
zsh compare.sh <(ls -mx1Cl 2>&1) <(./uls -mx1Cl 2>&1) "-mx1Cl"
zsh compare.sh <(ls -mx1lC 2>&1) <(./uls -mx1lC 2>&1) "-mx1lC"
zsh compare.sh <(ls -mxC1l 2>&1) <(./uls -mxC1l 2>&1) "-mxC1l"
zsh compare.sh <(ls -mxCl1 2>&1) <(./uls -mxCl1 2>&1) "-mxCl1"
zsh compare.sh <(ls -mxl1C 2>&1) <(./uls -mxl1C 2>&1) "-mxl1C"
zsh compare.sh <(ls -mxlC1 2>&1) <(./uls -mxlC1 2>&1) "-mxlC1"
zsh compare.sh <(ls -x1Clm 2>&1) <(./uls -x1Clm 2>&1) "-x1Clm"
zsh compare.sh <(ls -x1Cml 2>&1) <(./uls -x1Cml 2>&1) "-x1Cml"
zsh compare.sh <(ls -x1lCm 2>&1) <(./uls -x1lCm 2>&1) "-x1lCm"
zsh compare.sh <(ls -x1lmC 2>&1) <(./uls -x1lmC 2>&1) "-x1lmC"
zsh compare.sh <(ls -x1mCl 2>&1) <(./uls -x1mCl 2>&1) "-x1mCl"
zsh compare.sh <(ls -x1mlC 2>&1) <(./uls -x1mlC 2>&1) "-x1mlC"
zsh compare.sh <(ls -xC1lm 2>&1) <(./uls -xC1lm 2>&1) "-xC1lm"
zsh compare.sh <(ls -xC1ml 2>&1) <(./uls -xC1ml 2>&1) "-xC1ml"
zsh compare.sh <(ls -xCl1m 2>&1) <(./uls -xCl1m 2>&1) "-xCl1m"
zsh compare.sh <(ls -xClm1 2>&1) <(./uls -xClm1 2>&1) "-xClm1"
zsh compare.sh <(ls -xCm1l 2>&1) <(./uls -xCm1l 2>&1) "-xCm1l"
zsh compare.sh <(ls -xCml1 2>&1) <(./uls -xCml1 2>&1) "-xCml1"
zsh compare.sh <(ls -xl1Cm 2>&1) <(./uls -xl1Cm 2>&1) "-xl1Cm"
zsh compare.sh <(ls -xl1mC 2>&1) <(./uls -xl1mC 2>&1) "-xl1mC"
zsh compare.sh <(ls -xlC1m 2>&1) <(./uls -xlC1m 2>&1) "-xlC1m"
zsh compare.sh <(ls -xlCm1 2>&1) <(./uls -xlCm1 2>&1) "-xlCm1"
zsh compare.sh <(ls -xlm1C 2>&1) <(./uls -xlm1C 2>&1) "-xlm1C"
zsh compare.sh <(ls -xlmC1 2>&1) <(./uls -xlmC1 2>&1) "-xlmC1"
zsh compare.sh <(ls -xm1Cl 2>&1) <(./uls -xm1Cl 2>&1) "-xm1Cl"
zsh compare.sh <(ls -xm1lC 2>&1) <(./uls -xm1lC 2>&1) "-xm1lC"
zsh compare.sh <(ls -xmC1l 2>&1) <(./uls -xmC1l 2>&1) "-xmC1l"
zsh compare.sh <(ls -xmCl1 2>&1) <(./uls -xmCl1 2>&1) "-xmCl1"
zsh compare.sh <(ls -xml1C 2>&1) <(./uls -xml1C 2>&1) "-xml1C"
zsh compare.sh <(ls -xmlC1 2>&1) <(./uls -xmlC1 2>&1) "-xmlC1"
