#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct records_calls{
	
	char first_name[20];
	char last_name[30];
	char mobile_no[11];
	char email[20];
	char address[40];
	char date[11];
	int time;
	struct records_calls *next;	
	
};
struct personal_contact_info{
	
	char first_name[20];
	char last_name[30];
	char mobile_no[11];
	char email[20];
	int type;
	struct records_calls *rc;
	struct personal_contact_info* next;
	
}*Personal_list;

struct professional_contact_info{
	
	char first_name[20];
	char last_name[30];
	char mobile_no[11];
	char email[20];
	char office_number[11];
	char address[40];
	char institute[30];
	int type;
	struct records_calls *rc;
	struct professional_contact_info* next;
	
}* Professional_list;

typedef struct records_calls Record_calls;
typedef struct personal_contact_info Personal_info;
typedef struct professional_contact_info Professional_info;

Record_calls* new_recordCalls(){
	Record_calls *rc = (Record_calls*)malloc(sizeof(Record_calls));
	rc->next = NULL;
	return rc;
	
}
Personal_info* return_search(char* first_name,char* last_name,char* mobile_no){
	Personal_info* curr;
	curr = Personal_list;
	
	while(curr){
		if( strcmp(curr->first_name,first_name) == 0 && strcmp(curr->last_name,last_name) == 0 && strcmp(curr->mobile_no,mobile_no) == 0){
			break;
		}
		curr = curr->next;
	}
	return curr;  
}
void mergeContactInfoPersonal(Record_calls* rc,Personal_info* nptr){
	Record_calls *prev,*curr;
	prev = NULL;
	curr = nptr->rc;
	while(curr && curr->time >= rc->time){
		prev = curr;
		curr = curr->next; 
	} 
	if(prev == NULL){
		rc->next = curr;
		nptr->rc = rc;
	}else{
		rc->next = curr;
		prev->next = rc;
		
	}
	
}
void infoContactPersonal(char* first_name,char* last_name,char* mobile_no){
	Personal_info* nptr = return_search(first_name,last_name,mobile_no);
	
	int no;
	printf("ENTER THE NUMBER OF CONTACT YOU WANT TO INPUT : ");
	scanf("%d",&no);
	while(no--){
	Record_calls *rc = new_recordCalls();
		char demo[50];
		int min;
		printf("------------------------------------------------------------\n");
		printf("ENTER FIRST NAME OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->first_name,demo);
		printf("ENTER LAST NAME OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->last_name,demo);
		printf("ENTER MOBILE NUMBER OF CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->mobile_no,demo);
		printf("ENTER THE ADDRESS OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->address,demo);
		printf("ENTER EMAIL OF CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->email,demo);
		printf("ENTER THE DATE WHEN YOU MADE A CONTACT FOR EX YOU MADE A CONTACT ON 2 FEB 2022 THEN INPUT 2/02/2022: ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->date,demo);
		printf("ENTER DURATION OF CONTACT : ");
		fflush(stdin);
		scanf("%d",&min);
		rc->time  = min;
		mergeContactInfoPersonal(rc,nptr);
	}
	
}
void printRecordcalls(Record_calls* rc){
		printf("-----------------------------------------------------------------------\n");
	printf("NAME OF CONTACT : %s %s\n",rc->first_name,rc->last_name);
	printf("MOBILE NUMBER OF CONTACT : %s\n",rc->mobile_no);
	printf("EMAIL OF CONTACT : %s\n",rc->email);
	printf("ADDRESS OF CONTACT %s\n",rc->address);
	printf("DATE OF CALL MADE : %s\n",rc->address);
	printf("DURATION OF CALL : %d\n",rc->time);
		printf("-----------------------------------------------------------------------\n");
	
}

void DisplayinfoPersonal(char* first_name,char* last_name, char* mobile_no){
	Personal_info* nptr = return_search(first_name,last_name,mobile_no);
	Record_calls* rc = nptr->rc;
	if(rc == NULL){
		printf("LIST IS EMPTY!!!.....\n");
	}else{
		printf("ALL THE PERSON TO BE CALLED ARE...\n");
	}
	while(rc != NULL){
		printRecordcalls(rc);
		rc = rc->next;	
	}
	
}
Professional_info* return_searchProfessional(char* first_name,char* last_name,char* mobile_no){
	Professional_info* curr;
	curr = Professional_list;
	
	while(curr){
		if( strcmp(curr->first_name,first_name) == 0 && strcmp(curr->last_name,last_name) == 0 && strcmp(curr->mobile_no,mobile_no) == 0){
			break;
		}
		curr = curr->next;
	}
	return curr;  
}
void mergeContactInfoProfessional(Record_calls* rc,Professional_info* nptr){
	Record_calls *prev,*curr;
	prev = NULL;
	curr = nptr->rc;
	while(curr && curr->time >= rc->time){
		prev = curr;
		curr = curr->next; 
	} 
	if(prev == NULL){
		rc->next = curr;
		nptr->rc = rc;
	}else{
		rc->next = curr;
		prev->next = rc;
		
	}
	
}
void infoContactProfessional(char* first_name,char* last_name,char* mobile_no){
	Professional_info* nptr = return_searchProfessional(first_name,last_name,mobile_no);
	
	int no;
	printf("ENTER THE NUMBER OF CONTACT YOU WANT TO INPUT : ");
	scanf("%d",&no);
	while(no--){
	Record_calls *rc = new_recordCalls();
		char demo[50];
		int min;
		printf("------------------------------------------------------------\n");
		printf("ENTER FIRST NAME OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->first_name,demo);
		printf("ENTER LAST NAME OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->last_name,demo);
		printf("ENTER MOBILE NUMBER OF CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->mobile_no,demo);
		printf("ENTER THE ADDRESS OF THE CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->address,demo);
		printf("ENTER EMAIL OF CONTACT : ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->email,demo);
		printf("ENTER THE DATE WHEN YOU MADE A CONTACT FOR EX YOU MADE A CONTACT ON 2 FEB 2022 THEN INPUT 2/02/2022: ");
		fflush(stdin);
		gets(demo);
		strcpy(rc->date,demo);
		printf("ENTER DURATION OF CONTACT : ");
		fflush(stdin);
		scanf("%d",&min);
		rc->time  = min;
		mergeContactInfoProfessional(rc,nptr);
	}
	
}

void DisplayinfoProfessional(char* first_name,char* last_name, char* mobile_no){
	Professional_info* nptr = return_searchProfessional(first_name,last_name,mobile_no);
	Record_calls* rc = nptr->rc;
	if(rc == NULL){
		printf("LIST IS EMPTY!!!.....\n");
	}else{
		printf("ALL THE PERSON TO BE CALLED ARE...\n");
	}
	while(rc != NULL){
		printRecordcalls(rc);
		rc = rc->next;	
	}
	
}

void print_contactProfessional(Professional_info* nptr){
	if(nptr != NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("NAME : %s %s\n",nptr->first_name,nptr->last_name);
		printf("MOBILE NUMBER : %s\n",nptr->mobile_no);
		printf("EMAIL : %s\n",nptr->email);
		printf("OFFICE NUMBER : %s\n",nptr->office_number);
		printf("ADDRESS : %s\n",nptr->address);
		printf("INSTITUE NAME : %s\n",nptr->institute);
		printf("-----------------------------------------------------------------------\n");

	}else{
		printf("-----------------------------------------------------------------------\n");
		printf("WRONG CONTACT\n");
		printf("-----------------------------------------------------------------------\n");
	}
}

void print_contactPersonal(Personal_info* nptr){
	if(nptr != NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("NAME : %s %s\n",nptr->first_name,nptr->last_name);
		printf("MOBILE NUMBER : %s\n",nptr->mobile_no);
		printf("EMAIL : %s\n",nptr->email);
		printf("-----------------------------------------------------------------------\n");
	}else{
	printf("-----------------------------------------------------------------------\n");
		printf("WRONG CONTACT\n");
	printf("-----------------------------------------------------------------------\n");
	}
}

int check_name(char* name){
	int i=0,ans = 0;
	if(name[i] == '\0'){
		ans = 1;
	}
	while(name[i] != '\0' && ans == 0){
		if(name[i] != ' ' && (name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z')){
			ans = 1;
		}
		i++;
	}
	return ans;
}

int check_mobile_no(char* number){
	int i=0,ans = 0;
	if(number[i] == '\0'){
		ans = 1;
	}
	while(number[i] != '\0' && ans == 0){
		if(number[i] < '0' || number[i] >'9'){
			ans =1;
		}
		i++;
	}
	return ans;
}

int check_email(char *email){
	int i = 0,ans = 0;
	
	while(email[i] != '\0' && ans == 0){
		if(email[i] == '@'){
			ans = 1;
		}
		i++;
	}
	return ans;
}
	
Professional_info* new_professional_contact(){
	Professional_info* nptr = (Professional_info*)malloc(sizeof(Professional_info));
	nptr->next = NULL;	
	nptr->rc = NULL;
	return nptr;
}

Personal_info* new_personal_contact(){
	Personal_info* nptr = (Personal_info*)malloc(sizeof(Personal_info));
	nptr->next = NULL;		
	nptr->rc = NULL;
	return nptr;
}

void merge_personal(Personal_info* new_person){
	
	if(Personal_list == NULL){
		Personal_list = new_person;	
	
	}else{
		Personal_info *prev,*curr;
		int compare;
		
		prev = NULL;
		curr = Personal_list;
		compare = 1;
		
		while(curr != NULL && compare > 0 ){
			compare = strcmp(new_person->first_name,curr->first_name);
			
			if(compare == 0)
				compare = strcmp(new_person->last_name,curr->last_name);
			
			if(compare == 0)
				compare = strcmp(new_person->mobile_no,curr->mobile_no);
				
			if(compare > 0){
				prev = curr;
				curr = curr->next;
			}
		} 
			
		new_person->next = curr; 
		
		if( prev == NULL){
			Personal_list = new_person;
		}else{
			prev->next = new_person;
		}
	}

}

void merge_professional(Professional_info* new_person){
	
	if(Professional_list == NULL){
		Professional_list = new_person;	
	
	}else{
		Professional_info *prev,*curr;
		int compare;
		
		prev = NULL;
		curr = Professional_list;
		compare = 1;
		
		while(curr != NULL && compare > 0 ){
			compare = strcmp(new_person->first_name,curr->first_name);
			
			if(compare == 0)
				compare = strcmp(new_person->last_name,curr->last_name);
			
			if(compare == 0)
				compare = strcmp(new_person->mobile_no,curr->mobile_no);
				
			if(compare > 0){
				prev = curr;
				
				curr = curr->next;
			}
		} 
			
		new_person->next = curr; 
		if( prev == NULL){
			Professional_list = new_person;
		}else{
			prev->next = new_person;
		}
	}

}

void set_name(char* c){
	int i=0;
	while(c[i] != '\0'){
		c[i] = tolower(c[i]);
		i++;
	}
}

void add_personal_contact(){
	
	Personal_info* new_person = new_personal_contact();
	new_person->type = 1;
	
	int change = 0;
	fflush(stdin);
	printf("ENTER THE FIRST NAME OF THE PERSON : ");
	gets(new_person->first_name);
	
	if(check_name(new_person->first_name)){
		printf("May be your name is empty or your name contain letters other than uppercase and lower case letters....\nPress 1 if you want to change your name"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new name : ");
			fflush(stdin);
			gets(new_person->first_name);
			change = 0;
		}
	}
	set_name(new_person->first_name);
		
	printf("ENTER LAST NAME OF THE PERSON : ");
	gets(new_person->last_name);
	
	if(check_name(new_person->last_name)){
		printf("May be your name is empty or your name contain letters other than uppercase and lower case letters....\nPress 1 if you want to change your name"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new name : ");
			fflush(stdin);
			gets(new_person->last_name);
			change = 0;
		}
	}
	set_name(new_person->last_name);
	
	fflush(stdin);
	printf("ENTER THE CONTACT NUMBER OF THE PERSON : ");
	gets(new_person->mobile_no);
	
	if(check_mobile_no(new_person->mobile_no)){
		printf("your mobile number is empty or your Contact number should only contain numbers....\nPress 1 if you want to change your number"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new number : ");
			fflush(stdin);
			gets(new_person->mobile_no);
		}
	}
	
	fflush(stdin);
	printf("ENTER EMAIL OF THE PERSON : ");
	gets(new_person->email);
	
	if(check_email(new_person->email) == 0){
		printf("Your email is empty or your email does not contain '@'....\nPress 1 if you want to change your email"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new email : ");
			fflush(stdin);
			gets(new_person->email);
		}
	}
	
	new_person->type = 0;
	merge_personal(new_person);
	printf("NEW PERSON ADDED.....\n");
	printf("-----------------------------------------------------------------------\n");
	
}

void add_professional_contact(){

	Professional_info* new_person = new_professional_contact();
	int change = 0;
	
	new_person->type = 0;
	fflush(stdin);
	printf("ENTER THE FIRST NAME OF THE PERSON : ");
	gets(new_person->first_name);
	
	//checking if input name is correct
	if(check_name(new_person->first_name)){
		printf("May be your name is empty or your name contain letters other than uppercase and lower case letters....\nPress 1 if you want to change your name"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new name : ");
			fflush(stdin);
			gets(new_person->first_name);
			change = 0;
		}
	}
	set_name(new_person->first_name);	//converting letters to  lower case;
	
	printf("ENTER LAST NAME OF THE PERSON : ");
	gets(new_person->last_name);
	
	if(check_name(new_person->last_name)){
		printf("May be your name is empty or your name contain letters other than uppercase and lower case letters....\nPress 1 if you want to change your name"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("Enter new name : ");
			fflush(stdin);
			gets(new_person->last_name);
			change = 0;
		}
	}
	set_name(new_person->last_name);
	
	fflush(stdin);
	printf("ENTER CONTACT NUMBER OF THE PERSON : ");
	gets(new_person->mobile_no);
	
	if(check_mobile_no(new_person->mobile_no)){
		printf("your mobile number is empty or your Contact number should only contain numbers....\nPress 1 if you want to change your number"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			fflush(stdin);
			printf("Enter new number : ");
			gets(new_person->mobile_no);
		}
	}
	
	fflush(stdin);
	printf("ENTER EMAIL OF THE PERSON : ");
	gets(new_person->email);
	
	if(check_email(new_person->email) == 0){
		printf("Your email is empty or your email does not contain '@'....\nPress 1 if you want to change your email"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			fflush(stdin);
			printf("Enter new email : ");
			gets(new_person->email);
		}
	}
		
	fflush(stdin);
	printf("ENTER OFFICE NUMBER : ");
	gets(new_person->office_number);
		
	if(check_mobile_no(new_person->mobile_no)){
		printf("office number should only contain numbers....\nPress 1 if you want to change your number"
		" or else press any other key to continue...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			fflush(stdin);
			printf("Enter new number : ");
			gets(new_person->office_number);
		}
	}
		
	fflush(stdin);
	printf("ENTER ADDRESS : ");
	gets(new_person->address);
	
	fflush(stdin);
	printf("ENTER INSTITUTE NAME : ");
	gets(new_person->institute);
	merge_professional(new_person);
	printf("NEW PERSON ADDED.....\n");		
	printf("-----------------------------------------------------------------------\n");
	
}

void Display_contactPersonal(){
	Personal_info* tptr = Personal_list;
	int i = 1;
	if(tptr == NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("LIST IS EMPTY....\n");
		printf("-----------------------------------------------------------------------\n");
	}else
	{	printf("PERSONAL CONTACT LIST : \n");	
		printf("-----------------------------------------------------------------------\n");
		while(tptr != NULL){
			tptr->first_name[0] = toupper(tptr->first_name[0]);
			tptr->last_name[0] = toupper(tptr->last_name[0]);
			fflush(stdout);
			
			printf("%d.) Name of person: %s %s\n",i,tptr->first_name,tptr->last_name);
			tptr->first_name[0] = tolower(tptr->first_name[0]);
			tptr->last_name[0] = tolower(tptr->last_name[0]);
			fflush(stdout);
		
			printf("%d.) Contact number of person: %s\n",i,tptr->mobile_no);
//			printf("Address of person:\n%s",contact_list->address);
			fflush(stdout);
		
			printf("%d.) Email of person: %s\n",i,tptr->email);
			tptr = tptr->next;
			i++;
			printf("-----------------------------------------------------------------------\n");
		}
	}
	
}

void Display_contactProfessional(){
	Professional_info* tptr = Professional_list;
	int i = 1;
	if(tptr == NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("LIST IS EMPTY....\n");
		printf("-----------------------------------------------------------------------\n");
	}else
	{	printf("PROFESSIONAL CONTACT LIST : \n");	
		printf("-----------------------------------------------------------------------\n");
		while(tptr != NULL){
			tptr->first_name[0] = toupper(tptr->first_name[0]);
			tptr->last_name[0] = toupper(tptr->last_name[0]);
			fflush(stdout);
			
			printf("%d.) NAME : %s %s\n",i,tptr->first_name,tptr->last_name);
			tptr->first_name[0] = tolower(tptr->first_name[0]);
			tptr->last_name[0] = tolower(tptr->last_name[0]);
			fflush(stdout);
		
			printf("%d.) MOBILE NUMBER: %s\n",i,tptr->mobile_no);
//			printf("Address of person:\n%s",contact_list->address);
			fflush(stdout);
		
			printf("%d.) EMAIL : %s\n",i,tptr->email);
			tptr = tptr->next;
			i++;
			printf("-----------------------------------------------------------------------\n");
		}
	}
	
}

void copy_content_OfPersonal(Personal_info* nptr ,Personal_info* curr ){

	strcpy(nptr->first_name,curr->first_name);
	strcpy(nptr->last_name,curr->last_name);
	strcpy(nptr->mobile_no,curr->mobile_no);
	strcpy(nptr->email,curr->email);
	nptr->type = 0;
	
}

void copy_content_OfProfessional(Professional_info* nptr ,Professional_info* curr ){

	strcpy(nptr->first_name,curr->first_name);
	strcpy(nptr->last_name,curr->last_name);
	strcpy(nptr->mobile_no,curr->mobile_no);
	strcpy(nptr->email,curr->email);
	nptr->type = 1;
	strcpy(nptr->office_number,curr->office_number);
	strcpy(nptr->address,curr->address);
	strcpy(nptr->institute,curr->institute);
	
	
}

void Delete_ContactProfessional(Professional_info* prev,Professional_info* curr){
	
	if(prev == NULL)
		Professional_list  = Professional_list->next;
	else
		prev->next = curr->next;
	
	free(curr);
}

void Delete_ContactPersonal(Personal_info* prev,Personal_info* curr){
	
	if(prev == NULL)
		Personal_list  = Personal_list->next;
	else
		prev->next = curr->next;
	
	free(curr);
}

void Delete_ContactPersonal(char* del_first_name,char* del_last_name,char* del_numb){
	Personal_info* prev,*curr;
	prev = NULL;
	curr = Personal_list;
	
	while(curr && strcmp(del_first_name,curr->first_name) &&(strcmp(del_numb,curr->mobile_no) != 0 || strcmp(del_last_name,curr->last_name) !=0)){
		prev = curr;
		curr = curr->next;
	}
	
	if(curr == NULL){
		
		printf("CONTACT NOT FOUND!!!....\n");
		
	}else{
	if(prev == NULL){
		Personal_list = Personal_list->next;
	}else{
		prev->next = curr->next; 
	}
	printf("CONTACT DELETED....\n");
	free(curr);
	}
		printf("-----------------------------------------------------------------------\n");

}

void Delete_ContactProfessional(char* del_first_name,char* del_last_name,char* del_numb){
	Professional_info* prev,*curr;
	prev = NULL;
	curr = Professional_list;
	
	while(curr && strcmp(del_first_name,curr->first_name) &&(strcmp(del_numb,curr->mobile_no) != 0 || strcmp(del_last_name,curr->last_name) !=0)){
		prev = curr;
		curr = curr->next;
	}
	
	if(curr == NULL){
		
		printf("CONTACT NOT FOUND!!!....\n");
		
	}else{
	if(prev == NULL){
		Professional_list = Professional_list->next;
	}else{
		prev->next = curr->next; 
	}
	printf("CONTACT DELETED....\n");
	free(curr);
	}
}

void Edit_contactPersonal(char* del_firstName,char* del_lastName,char* del_numb){
	
	Personal_info* prev,*curr,*new_modify;
	new_modify = new_personal_contact();
	prev = NULL;
	curr = Personal_list;
	int t = 1;
	while(curr && strcmp(del_firstName,curr->first_name) &&(strcmp(del_numb,curr->mobile_no) != 0 || strcmp(del_lastName,curr->last_name) !=0)){
		prev = curr;
		curr = curr->next;
	}
		printf("-----------------------------------------------------------------------\n");

	
	if(curr != NULL){
		
		copy_content_OfPersonal(new_modify,curr);
		Delete_ContactPersonal(prev,curr);
		char modified_content[50];
		while(t != 0){
			printf("Enter 0 if you don't want to modify anything\nEnter 1 to modify name\nEnter 2 to modify contact number \nEnter 3 to modify email\n");
			scanf("%d",&t);
	      
			if(t == 1){
				fflush(stdin);
				printf("ENTER FIRST NAME : ");
				gets(modified_content);
				
				strcpy(new_modify->first_name,modified_content);
				
				fflush(stdin);
				printf("ENTER LAST NAME : ");
				gets(modified_content);
				
				strcpy(new_modify->last_name,modified_content);
				
			}else if(t == 2){
				printf("ENTER MOBILE NUMBER : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->mobile_no,modified_content);
			
			}else if(t == 3){
				printf("ENTER EMAIL : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->email,modified_content);
				
			}
		}
		
		merge_personal(new_modify);
		
	printf("INFORMATION EDITED.....\n");
	}else{
		printf("CONTACT NOT FOUND!!!.....\n");
	}
		printf("-----------------------------------------------------------------------\n");

}

void Edit_contactProfessional(char* del_firstName,char* del_lastName,char* del_numb){
	
	Professional_info* prev,*curr,*new_modify;
	new_modify = new_professional_contact();
	prev = NULL;
	curr = Professional_list;
	int t = 1;
	while(curr && strcmp(del_firstName,curr->first_name) &&(strcmp(del_numb,curr->mobile_no) != 0 || strcmp(del_lastName,curr->last_name) !=0)){
		prev = curr;
		curr = curr->next;
	}
		printf("-----------------------------------------------------------------------\n");
	if(curr != NULL){
		
		copy_content_OfProfessional(new_modify,curr);
		Delete_ContactProfessional(prev,curr);
		char modified_content[50];
		
		while(t != 0){
			printf("Enter 0 if you dont want to modify anything\nEnter 1 to modify name\nEnter 2 to modify contact number \nEnter 3 to modify email\n"
			"Enter 4 to modify office number\n Enter 5 to modify address\nEnter 6 to modify institute name\"");
			scanf("%d",&t);
	      
			if(t == 1){
				printf("ENTER FIRST NAME : ");
				fflush(stdin);
				gets(modified_content);
				strcpy(new_modify->first_name,modified_content);
				
				printf("ENTER LAST NAME : ");
				fflush(stdin);
				gets(modified_content);
				strcpy(new_modify->last_name,modified_content);
				
			}else if(t == 2){
				printf("ENTER MOBILE NUMBER : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->mobile_no,modified_content);
			
			}else if(t == 3){
				printf("ENTER EMAIL : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->email,modified_content);
				
			}else if(t == 4){
				printf("ENTER OFFICE NUMBER : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->office_number,modified_content);
			
			}else if(t == 5){
				printf("ENTER ADDRESS : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->address,modified_content);
				
			}else if(t == 6){
				printf("ENTER INSTITUTE NAME : ");
				fflush(stdin);
				gets(modified_content);
				fflush(stdin);
				strcpy(new_modify->institute,modified_content);
				
			}
		}
		
		merge_professional(new_modify);
	printf("INFORMATION EDITED.....\n");
	}else{	
		printf("CONTACT NOT FOUND....\n");
	}
	printf("-----------------------------------------------------------------------\n");
}

void searchByNamePersonal(char* firstName,char* lastName){
	Personal_info* nptr = Personal_list;
	int b = 0;
	while(nptr != NULL){
		
		if(strcmp(firstName,nptr->first_name) == 0 && strcmp(lastName,nptr->last_name) == 0){
			if(b == 0){
				printf("-----------------------------------------------------------------------\n");
				printf("ALL THE CONTACT WITH THE GIVEN NAME: \n");
				printf("-----------------------------------------------------------------------\n");
				b = 1;
			}
			print_contactPersonal(nptr);
			
		}
		nptr = nptr->next;
	}
	if(b == 0){
		printf("-----------------------------------------------------------------------\n");
		printf("THERE ARE NO CONTACT WITH GIVEN NAME!!!...\n");
		printf("-----------------------------------------------------------------------\n");
	}
	printf("-----------------------------------------------------------------------\n");
}

void searchByNumberPersonal(char* number ){
	Personal_info* nptr = Personal_list;
	int b = 0;
	while(nptr != NULL){
		
		if(strcmp(number,nptr->mobile_no) == 0){
			if(b == 0){
				printf("-----------------------------------------------------------------------\n");
				printf("ALL THE CONTACT WITH THE GIVEN NUMBER: \n");
				printf("-----------------------------------------------------------------------\n");
				b = 1;
			}
			print_contactPersonal(nptr);
		}
			
		nptr = nptr->next;
	}
	if(b == 0){
		printf("-----------------------------------------------------------------------\n");
		printf("THERE ARE NO CONTACT WITH GIVEN NUMBER!!!...\n");
		printf("-----------------------------------------------------------------------\n");
	}
}

void searchByNameProfessional(char* firstName,char* lastName){
	Professional_info* nptr = Professional_list;
	int b = 0;
	while(nptr != NULL){
		
		if(strcmp(firstName,nptr->first_name) == 0 && strcmp(lastName,nptr->last_name) == 0){
			if(b == 0){
				printf("-----------------------------------------------------------------------\n");
				printf("ALL THE CONTACT WITH THE GIVEN Name: \n");
				printf("-----------------------------------------------------------------------\n");
				b = 1;
			}
			print_contactProfessional(nptr);
			
		}
		nptr = nptr->next;
	}
	if(b == 0){
		printf("-----------------------------------------------------------------------\n");
		printf("THERE ARE NO CONTACT WITH GIVEN NAME!!!...\n");
		printf("-----------------------------------------------------------------------\n");
	}
	printf("-----------------------------------------------------------------------\n");
}

void searchByNumberProfessional(char* number ){
	Professional_info* nptr = Professional_list;
	int b = 0;
	while(nptr != NULL){
		
		if(strcmp(number,nptr->mobile_no) == 0){
			if(b == 0){
				printf("-----------------------------------------------------------------------\n");
				printf("ALL THE CONTACT WITH THE GIVEN NUMBER: \n");
				printf("-----------------------------------------------------------------------\n");
				b = 1;
			}
			print_contactProfessional(nptr);
		}
			
		nptr = nptr->next;
	}
	if(b == 0){
		printf("-----------------------------------------------------------------------\n");
		printf("THERE ARE NO CONTACT WITH GIVEN NUMBER!!!...\n");
		printf("-----------------------------------------------------------------------\n");
	}
}

void FrontBackSplitPersonal(Personal_info* source,Personal_info** frontRef, Personal_info** backRef){
   
    Personal_info* fast = source->next;
    Personal_info* slow = source;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
    
}

Personal_info* SortedMergePersonal(Personal_info* a, Personal_info* b){

    Personal_info* result = NULL;
    
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 	
    int compare = strcmp(a->first_name,b->first_name);
    
    if(compare == 0)
    	compare = strcmp(a->last_name,b->last_name);
    	
	if(compare < 0){
 		result = a;
 		a = a->next;
	}else if(compare > 0){
	 	result = b;
	 	b = b->next;
	}else{
		compare = strcmp(a->mobile_no,b->mobile_no);
	 	if(compare > 0){
	 		result = b;
			b = b->next;	
		}else{
			result = a;
			a = a->next;
		}
	 }
	 Personal_info* ff = result;
	 
 	while(a != NULL && b != NULL){
 		
 		compare = strcmp(a->first_name,b->first_name);
   		
		if(compare == 0)
    		compare = strcmp(a->last_name,b->last_name);
 		
 		if(compare < 0){
 			ff->next = a;
 			ff = a;
 			a = a->next;
		}else if(compare > 0){
	 		ff->next = b;
	 		ff = b;
			b = b->next;
		}else{
			compare = strcmp(a->mobile_no,b->mobile_no);
	 		if(compare > 0){
	 			ff->next = b;
				ff = b;
				b = b->next;	
			}else{
				ff->next = a;
				ff = a;
				a = a->next;
			}
	 	}	
	}
	if(a == NULL){
		ff->next = b; 
	}else{
		ff->next = a;
	}
	
    return result;
}

void MergeSortPersonal(Personal_info** headRef ){
	
 
    Personal_info* head = *headRef,*a,*b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplitPersonal(head, &a, &b);
 	
    MergeSortPersonal(&a);
    MergeSortPersonal(&b);
    
    *headRef = SortedMergePersonal(a, b);
}

void FrontBackSplitProfessional(Professional_info* source,Professional_info** frontRef, Professional_info** backRef){
   
    Professional_info* fast = source->next;
    Professional_info* slow = source;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
    
}

Professional_info* SortedMergeProfessional(Professional_info* a, Professional_info* b){

    Professional_info* result = NULL;
    
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 	
    int compare = strcmp(a->first_name,b->first_name);
    
    if(compare == 0)
    	compare = strcmp(a->last_name,b->last_name);
    	
	if(compare < 0){
 		result = a;
 		a = a->next;
	}else if(compare > 0){
	 	result = b;
	 	b = b->next;
	}else{
		compare = strcmp(a->mobile_no,b->mobile_no);
	 	if(compare > 0){
	 		result = b;
			b = b->next;	
		}else{
			result = a;
			a = a->next;
		}
	 }
	 Professional_info* ff = result;
	 
 	while(a != NULL && b != NULL){
 		
 		compare = strcmp(a->first_name,b->first_name);
   		
		if(compare == 0)
    		compare = strcmp(a->last_name,b->last_name);
 		
 		if(compare < 0){
 			ff->next = a;
 			ff = a;
 			a = a->next;
		}else if(compare > 0){
	 		ff->next = b;
	 		ff = b;
			b = b->next;
		}else{
			compare = strcmp(a->mobile_no,b->mobile_no);
	 		if(compare > 0){
	 			ff->next = b;
				ff = b;
				b = b->next;	
			}else{
				ff->next = a;
				ff = a;
				a = a->next;
			}
	 	}	
	}
	if(a == NULL){
		ff->next = b; 
	}else{
		ff->next = a;
	}
	
    return result;
}

void MergeSortProfessional(Professional_info** headRef ){
	
 
    Professional_info* head = *headRef,*a,*b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplitProfessional(head, &a, &b);
 	
    MergeSortProfessional(&a);
    MergeSortProfessional(&b);
    
    *headRef = SortedMergeProfessional(a, b);
}

void DecendingPersonal(Personal_info* nptr){
	if(nptr == NULL){
		return ;
	}
	DecendingPersonal(nptr->next);
	
	print_contactPersonal(nptr);
	
}

void DecendingProfessional(Professional_info* nptr){
	if(nptr == NULL){
		return ;
	}
	DecendingProfessional(nptr->next);
	
	print_contactProfessional(nptr);
	
}

void clean_heap(){
	Personal_info* tptr;
	Professional_info* cptr;
	
	while(Personal_list != NULL){
		tptr = Personal_list;
		Personal_list = Personal_list->next;
		free(tptr); 
	}
	
	while(Professional_list != NULL){
		cptr = Professional_list;
		Professional_list = Professional_list->next;
		free(cptr); 	
	}
}

void remove_duplicatePersonal(){
	Personal_info* tptr;
	tptr = Personal_list;
		printf("-----------------------------------------------------------------------\n");

	if(tptr == NULL){
		printf("LIST IS EMPTY...\n");
	}else{
		Personal_info* prev = tptr,*temp;
		tptr = tptr->next;
		while(tptr != NULL){
			while(tptr != NULL && strcmp(prev->first_name,tptr->first_name) == 0 &&strcmp(prev->last_name,tptr->last_name) == 0 && strcmp(prev->mobile_no,tptr->mobile_no) == 0){
				temp = tptr;
				tptr = tptr->next;
				free(temp);
			}
			prev = prev->next = tptr;
			if(tptr != NULL)
				tptr = tptr->next;
			
		}
		printf("ALL DUPLICATES DELETED!!!...\n");
	}
		printf("-----------------------------------------------------------------------\n");

}

void remove_duplicateProfessional(){
	Professional_info* tptr;
	tptr = Professional_list;
		printf("-----------------------------------------------------------------------\n");

	if(tptr == NULL){
		printf("LIST IS EMPTY...\n");
	}else{
		Professional_info* prev = tptr,*temp;
		tptr = tptr->next;
		while(tptr != NULL){
			while(tptr != NULL && strcmp(prev->first_name,tptr->first_name) == 0 &&strcmp(prev->last_name,tptr->last_name) == 0 && strcmp(prev->mobile_no,tptr->mobile_no) == 0){
				temp = tptr;
				tptr = tptr->next;
				free(temp);
			}
			prev = prev->next = tptr;
			if(tptr != NULL)
				tptr = tptr->next;
			
		}
		printf("ALL DUPLICATES DELETED...\n");
	}	
	printf("-----------------------------------------------------------------------\n");

}

int main(){
	Personal_list = NULL;
	Professional_list = NULL;
	int n,no_contact,y=1,type;
	//nptr is crated to be used in function like sort as existing list is already sorted and 
	// in union of two list 
	Personal_info* nptr = new_personal_contact();
	strcpy(nptr->email , "23@");
	strcpy(nptr->first_name , "bufin");
	strcpy(nptr->last_name , "grkf");
	strcpy(nptr->mobile_no , "5537");
	
	nptr->next = new_personal_contact();
	strcpy(nptr->next->email , "23@");
	strcpy(nptr->next->first_name , "bufin");
	strcpy(nptr->next->last_name , "grkf");
	strcpy(nptr->next->mobile_no , "4537");
	
	nptr->next->next = new_personal_contact();
	strcpy(nptr->next->next->email , "23@");
	strcpy(nptr->next->next->first_name , "aufin");
	strcpy(nptr->next->next->last_name , "grkf");
	strcpy(nptr->next->next->mobile_no , "4537");
	
	while(y){
	printf(
	"|--------------------------------------------------------|\n"
	"|Enter |      Function to be performed                   |\n"
	"|--------------------------------------------------------|\n"
    "|  1   |  to add a contact                               |\n"
	"|  2   |  to delete a conatact                           |\n"
	"|  3   |  to edit a existing contact                     |\n"
	"|  4   |  to display contact                             |\n"
	"|  5   |  to search a contact                            |\n"
	"|  6   |  to sort the list                               |\n"
	"|  7   |  to merge two sorted linked list                |\n"
	"|  8   |  to remove duplicates from a sorted list        |\n"
	"|  9   |  to display information about contact           |\n"
	"|  10  |  to add information about contact               |\n"
	"|______|_________________________________________________|\n");
	
	scanf("%d",&n);
	if(n == 1){
		int no;
		printf("Enter number of contact to be added : ");
		scanf("%d",&no);
		while(no--){
			printf("Enter the type of contact 1 for personal and 0 for professional : ");
			scanf("%d",&type);
			if(type == 1){
				add_personal_contact();
				Display_contactPersonal();
			}else{
				add_professional_contact();
			}
		}
	}
	else if(n == 2){
		
		printf("Enter name and contact number of person you want to delete contact\n");
		char del_first_name[40];
		char del_last_name[40];
		char del_numb[11];
		
		printf("Enter the first name of contact\n");
		fflush(stdin);
		gets(del_first_name);
		set_name(del_last_name);
		
		printf("Enter the last name of contact\n");
		fflush(stdin);
		gets(del_last_name);
		set_name(del_last_name);
		
		printf("Enter the number of contact\n");
		fflush(stdin);
		gets(del_numb);
		
		printf("1 for personal contact and 0 for professional : ");
		scanf("%d",&type);
		if(type == 1){
			Delete_ContactPersonal(del_first_name,del_last_name,del_numb);
		}else{
			Delete_ContactProfessional(del_first_name,del_last_name,del_numb);	
		}
		
	}
   else if(n == 3){
		fflush(stdin);
		char del_first_name[20];
		char del_last_name[30];
		char del_numb[11];
		
		printf("Enter the first name of contact\n");
		fflush(stdin);
		gets(del_first_name);
		set_name(del_first_name);
		
		printf("Enter the last name of contact\n");
		fflush(stdin);
		gets(del_last_name);
		set_name(del_last_name);
		
		printf("Enter the number of contact\n");
		fflush(stdin);
		gets(del_numb);
		
		printf("Enter the type of contact : ");
		scanf("%d",&type);
		if(type == 1){
			Edit_contactPersonal(del_first_name,del_last_name,del_numb);
		}else{
			Edit_contactProfessional(del_first_name,del_last_name,del_numb);	
		}
	
	}
	else if(n == 4){
		printf("ENTER 1 TO DISPLAY PERSONAL LIST\nENTER 0 TO DISPLAY PROFESSIONAL LIST\n ");
		scanf("%d",&type);
		if(type == 1){
			Display_contactPersonal();
		}else{
			Display_contactProfessional();
		}
	
	}
	else if(n == 5){
		
		int no;
		printf("ENTER THE TYPE OF CONTACT i.e. PERSONAL OR PROFESSIONAL : ");
		scanf("%d",&type);
		printf("PRESS 1 TO SEARCH BY NUMBER\nPRESS 2 TO SEARCH BY NAME\n");
		scanf("%d",&no);
	if(type == 1){
		if(no == 1){
			char numb[11];
			fflush(stdin);
			printf("ENTER THE NUMBER : ");
			gets(numb);
			searchByNumberPersonal(numb);
		}else{
			char first_name[20];
			char last_name[30];
			
			fflush(stdin);
			printf("ENTER THE FIRST NAME : ");
			gets(first_name);
			set_name(first_name);
			
			printf("ENTER THE LAST NAME : ");
			gets(last_name);
			set_name(last_name);
			searchByNamePersonal(first_name,last_name);
		}
		}else{
		if(no == 1){
			char numb[11];
			fflush(stdin);
			printf("ENTER THE NUMBER : ");
			gets(numb);
			searchByNumberProfessional(numb);
		}else{
			char first_name[20];
			char last_name[30];
			
			fflush(stdin);
			printf("ENTER THE FIRST NAME : ");
			gets(first_name);
			set_name(first_name);
			
			printf("ENTER THE LAST NAME : ");
			gets(last_name);
			set_name(last_name);
			searchByNameProfessional(first_name,last_name);
		}
	}
	}
	else if(n == 6){
		int asc;
		printf("ENTER 1 TO SORT IN ASCENDING ORDER OR 0 TO SORT IN DESCENDING ORDER : ");
		scanf("%d",&asc);
		fflush(stdin);
		printf("ENTER 1 TO PRINT PERSONAL LIST OR 2 FOR PROFESSIONAL LIST : ");
		scanf("%d",&type);
		if(type == 1){
			if(asc == 1){
				MergeSortPersonal(&Personal_list);
				
			}else{
				MergeSortPersonal(&Personal_list);
				DecendingPersonal(Personal_list);
			}
		}else{
			if(asc == 1){
				MergeSortProfessional(&Professional_list);
			}else{
				DecendingProfessional(Professional_list);
			}
			
		}
	}
	else if(n == 7){
		
		printf("ENTER 1 TO PRINT PERSONAL LIST OR 2 FOR PROFESSIONAL LIST : ");
		scanf("%d",&type);
		if(type == 1){
		Personal_list = SortedMergePersonal(nptr,Personal_list);
		}else{
//			Professional_list  = SortedMergeProfessional(Professional_list,Professional_list);
		}

	}
 else if(n == 8){
		printf("ENTER 1 TO PRINT PERSONAL LIST OR 2 FOR PROFESSIONAL LIST : ");
		scanf("%d",&type);
		if(type == 1){
			remove_duplicatePersonal();
		}else{
			remove_duplicateProfessional();
		}
	}else if(n == 9){
		printf("ENTER 1 TO PRINT PERSONAL LIST OR 2 FOR PROFESSIONAL LIST : ");
		scanf("%d",&type);
		char f[20],l[30],m[11];
		printf("ENTER THE FIRST NAME : ");
		fflush(stdin);
		gets(f);
		printf("ENTER TEH LAST NAME : ");
		fflush(stdin);
		gets(l);
		printf("ENTER THE MOBILE NUMBER : ");
		fflush(stdin);
		gets(m);
		DisplayinfoPersonal(f,l,m);
		
	}else if(n == 10){
		printf("ENTER 1 TO PRINT PERSONAL LIST OR 2 FOR PROFESSIONAL LIST : ");
		scanf("%d",&type);
		char f[20],l[30],m[11];
		printf("ENTER THE FIRST NAME : ");
		fflush(stdin);
		gets(f);
		printf("ENTER TEH LAST NAME : ");
		fflush(stdin);
		gets(l);
		printf("ENTER THE MOBILE NUMBER : ");
		fflush(stdin);
		gets(m);
		infoContactPersonal(f,l,m);
	}
	printf("Enter 0 to break the loop or press any other number to continue\n");
	scanf("%d",&y);
	}
	clean_heap();
	return 0;
}
