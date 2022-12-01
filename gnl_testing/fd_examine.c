#include "fd_examine.h"

void	print_file_struct_properties(char *label, FILE *p_file)
{
	printf("label,size,member type,member name,member description,value,offset from beginning of struct\n");
	printf("whole struct,%ld,,,\n", sizeof(*p_file));
	printf("%s,%d,int,_flags,no description,%d,%ld\n", label, 8, stdin->_flags, (((unsigned long int) &(stdin->_flags)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_read_ptr,Current read pointer,%p,%ld\n", label, 8, stdin->_IO_read_ptr, (((unsigned long int) &(stdin->_IO_read_ptr)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_read_end,End of get area,%p,%ld\n", label, 8, stdin->_IO_read_end, (((unsigned long int) &(stdin->_IO_read_end)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_read_base,Start of putback+get area,%p,%ld\n", label, 8, stdin->_IO_read_base, (((unsigned long int) &(stdin->_IO_read_base)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_write_base,Start of put area,%p,%ld\n", label, 8, stdin->_IO_write_base, (((unsigned long int) &(stdin->_IO_write_base)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_write_ptr,Current put pointer,%p,%ld\n", label, 8, stdin->_IO_write_ptr, (((unsigned long int) &(stdin->_IO_write_ptr)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_write_end,End of put area,%p,%ld\n", label, 8, stdin->_IO_write_end, (((unsigned long int) &(stdin->_IO_write_end)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_buf_base,Start of reserve area,%p,%ld\n", label, 8, stdin->_IO_buf_base, (((unsigned long int) &(stdin->_IO_buf_base)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_buf_end,End of reserve area,%p,%ld\n", label, 8, stdin->_IO_buf_end, (((unsigned long int) &(stdin->_IO_buf_end)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_save_base,Pointer to start of non-current get area,%p,%ld\n", label, 8, stdin->_IO_save_base, (((unsigned long int) &(stdin->_IO_save_base)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_backup_base,Pointer to first valid character of backup area,%p,%ld\n", label, 8, stdin->_IO_backup_base, (((unsigned long int) &(stdin->_IO_backup_base)) - ((unsigned long int) stdin)));
	printf("%s,%d,char *,_IO_save_end,Pointer to end of non-current get area,%p,%ld\n", label, 8, stdin->_IO_save_end, (((unsigned long int) &(stdin->_IO_save_end)) - ((unsigned long int) stdin)));
	printf("%s,%d,struct _IO_marker *,_markers,no description,%p,%ld\n", label, 8, stdin->_markers, (((unsigned long int) &(stdin->_markers)) - ((unsigned long int) stdin)));
	printf("%s,%d,struct _IO_FILE *,_chain,no description,%p,%ld\n", label, 8, stdin->_chain, (((unsigned long int) &(stdin->_chain)) - ((unsigned long int) stdin)));
	printf("%s,%d,int,_fileno,no description,%d,%ld\n", label, 4, stdin->_fileno, (((unsigned long int) &(stdin->_fileno)) - ((unsigned long int) stdin)));
	//printf("%s,%d,int,_blksize,no description,%d,%ld\n", label, 4, stdin->_blksize, (((unsigned long int) &(stdin->_blksize)) - ((unsigned long int) stdin)));
	printf("%s,%d,int,_flags2,no description,%d,%ld\n", label, 4, stdin->_flags2, (((unsigned long int) &(stdin->_flags2)) - ((unsigned long int) stdin)));
	printf("%s,%d,_IO_off_t,_old_offset,This used to be _offset but it's too small,%ld,%ld\n", label, 8, stdin->_old_offset, (((unsigned long int) &(stdin->_old_offset)) - ((unsigned long int) stdin)));
	printf("%s,%d,unsigned short,_cur_column,no description,%d,%ld\n", label, 2, stdin->_cur_column, (((unsigned long int) &(stdin->_cur_column)) - ((unsigned long int) stdin)));
	printf("%s,%d,signed char,_vtable_offset,no description,%d,%ld\n", label, 8, stdin->_vtable_offset, (((unsigned long int) &(stdin->_vtable_offset)) - ((unsigned long int) stdin)));
	printf("%s,%d,char,_shortbuf,no description,%s,%ld\n", label, 8, stdin->_shortbuf, (((unsigned long int) &(stdin->_shortbuf)) - ((unsigned long int) stdin)));
	printf("%s,%d,_IO_lock_t *,_lock,no description,%p,%ld\n", label, 8, stdin->_lock, (((unsigned long int) &(stdin->_lock)) - ((unsigned long int) stdin)));

	return ;
}
