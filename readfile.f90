  !*********************************************************
  !This program is going to read from an already existing
  !file and print out to screen the information that it sees
  !*********************************************************
PROGRAM READFILE
  INTEGER:: I,J,K,L
  OPEN(UNIT = 1, FILE = "linear_interp_data.txt")
  
  CLOSE(1)
