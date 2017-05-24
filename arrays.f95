program arrays
  integer, pointer, dimension(:,:) :: i => null() !Initilizes a pointer as disassociated when it is declared
  integer, allocatable, dimension(:) :: j         !Allocates space on the heap for the array j
  integer, pointer :: k
  write(*,*) associated(i), associated(k)
  allocate (i(10,20),k)
  write(*,*) associated(i), shape(i)
  write(*,*) associated(k)
  deallocate (i,k)
  write(*,*) allocated(j)
  allocate (j(10))
  write(*,*) allocated(j), shape(j)
  deallocate (j)
end program arrays
