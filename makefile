TARGET = app

default:
	sparc-elf-gcc --std=c99 app.c mf624.c -o $(TARGET)


run:
	qemu-system-sparc -M leon3_generic -m 64M -kernel $(TARGET) -nographic
