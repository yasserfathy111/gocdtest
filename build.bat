ctc -E main.c -o main.i

#cins main.i -c .\rvs_instr.h -c .\rvs_ipoint.h --exf .\tmp\xsc\exf.exf --force-hline -o .\tmp\instr\%%f.c --xsc .\tmp\xsc\%%f.xsc --cext ./TASKING-custom.cext --nbits 31
