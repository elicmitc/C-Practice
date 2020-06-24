struct university {
  char name[ 20 ];
  char* abbreviatedName; 
  unsigned int numberofStudents;
  struct {char phoneNumber[ 11 ]; 
  char address[ 60 ];
  char city[ 20 ]; char state[ 3 ];
  int zipCode;
  } physical_address;
} universityRecord, *universityPtr; 
universityPtr = &universityRecord;

//a)
printf("%s", universirtyRecord.name);
//b) 
printf(" %s",(*universirtyPtr).name);
//c) 
printf(" %s",universirtyRecord.abbreviatedName);
//d) 
printf(" %s", (*universirtyPtr).abbreviatedName); 
//e)
printf(" %s", universityRecord.abbreviatedName = ""+);      
printf("%c", universityRecov.abbreviatedName);
//f) 
printf(" %s",universityrecord.physical_address.phoneNumber);
//g)
printf(" %s", universityPtr->physical_address.address);
//h)
printf(" %d", universityRecord.physical_addeess.zipCode);
//i) 
printf(" %d",universityPtr->physical_address.zipCode); 
//j)
 int i;
for(i=0; i<5; ++i){
  printf(" %d", (universityReecod+i).physical_address.zipCode; 
	 }
//k)
int i;
for(i=0; i<5; ++i){
  printf(" %d", (universityPtr+i)->physical_address.zipCode; 
	 }
