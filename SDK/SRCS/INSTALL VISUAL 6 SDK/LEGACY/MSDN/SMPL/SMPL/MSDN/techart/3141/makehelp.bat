@del generic.err > nul
@start /w c:\binw\hcrtf -x generic.hpj
@if exist generic.err type generic.err  