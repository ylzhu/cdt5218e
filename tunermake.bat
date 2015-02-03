call clean
if exist ..\mipsel-elf\libcdt1028drv.a del ..\mipsel-elf\libcdt1028drv.a
make
copy libcdt1028drv.a ..\MIPSEL-ELF\libcdt1028drv.a
copy libcdt1028drv.a ..\atv\libcdt1028drv.a
cd ..
call clean
call sej
cd cdt1028drv