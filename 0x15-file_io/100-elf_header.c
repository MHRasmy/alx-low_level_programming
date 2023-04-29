#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
	int fd;
	Elf32_Ehdr header;

	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		fprintf(stderr, "Error: Cannot open %s: %s\n", argv[1], strerror(errno));
		exit(98);
	}

	if (lseek(fd, 0, SEEK_SET) == -1) 
	{   
		fprintf(stderr, "Error: Cannot lseek %s: %s\n", argv[1], strerror(errno));
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header)) 
	{
		fprintf(stderr, "Error: Cannot read header of %s: %s\n", argv[1], strerror(errno));
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || 
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3) 
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   %2x %2x %2x %2x\n", header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
			header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
	printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s, %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian",  
			"little endian"); 
	printf("  Version:%d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:%s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "<unknown: %x>", header.e_ident[EI_OSABI]);
	printf("  ABI Version:%d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:%s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" : header.e_type == ET_DYN ? "DYN (Shared object file)" : "<unknown: %x>", header.e_type);
	printf("  Entry point address:0x%x\n", header.e_entry);

	close(fd);
	return 0;
}
