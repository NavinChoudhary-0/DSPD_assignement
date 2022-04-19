#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ll long long int
struct personal_node{
	char first_name[20];
	char last_name[30];
	ll mobile_no;
	char email[30];
	int type;
	struct personal_node *left;
	struct personal_node *right;
	int height;
} *Personal_list, *NumberPersonal;

struct professional_node{
	char first_name[20];
	char last_name[30];
	ll mobile_no;
	char email[30];
	int type;
	ll office_no;
	char address[50];
	char office[40];
	struct professional_node *left;
	struct professional_node *right;
	int height;
} *Professional_list, *NumberProfessional;

//Personal_list and Professional list are sorted according to name 
//NumberPersonal and NumberProfessional are sorted according to mobile number

typedef struct personal_node Personal;
typedef struct professional_node Professional;

Personal* insertNumberPersonal(Personal*,Personal*);
Professional* insertNumberProfessional(Professional*,Professional*);

int comparePersonalName(Personal* p1, Personal* p2){
	int compare;
	compare = strcmp(p1->first_name,p2->first_name);
	if(compare == 0)
		compare = strcmp(p1->last_name,p2->last_name);
	
	return compare;
}

int compareProfessionalName(Professional* p1,Professional*  p2){
	int compare;
	compare = strcmp(p1->first_name,p2->first_name);
	if(compare == 0)
		compare = strcmp(p1->last_name,p2->last_name);
	return compare;
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

int max(int a, int b){
	return (a > b)? a : b;
}

void setName(char* c){
	int i=0;
	while(c[i] != '\0'){
		c[i] = tolower(c[i]);
		i++;
	}
}

int comparePersonal(Personal* p1, Personal* p2){
	int compare;
	compare = strcmp(p1->first_name,p2->first_name);
	if(compare == 0){
		compare = strcmp(p1->last_name,p2->last_name);
	
		if(compare == 0){
			if(p1->mobile_no == p2->mobile_no)
				compare = 0;
			else
				compare = (p1->mobile_no > p2->mobile_no)? 1 : -1;	
		}
		
	}
	return compare;
}

int compareProfessional(Professional* p1, Professional* p2){
	int compare;
	compare = strcmp(p1->first_name,p2->first_name);
	if(compare == 0){
		compare = strcmp(p1->last_name,p2->last_name);
		
		if(compare == 0)
			compare = (p1->mobile_no > p2->mobile_no)? 1 : -1;
	}
	return compare;
}

int heightPersonal(Personal *p){
	if (p == NULL)
		return 0;
		
	return p->height;
}

int heightProfessional(Professional *p){
	if (p == NULL)
		return 0;
		
	return p->height;
}

Personal* newPersonal(){
	
	Personal* node = (Personal*)malloc(sizeof(Personal));
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	node->type = 0;
	return node;
	
}

Personal* newPersonal(char* first_name, char* last_name, int mobile_no ){
	
	Personal* node = (Personal*)malloc(sizeof(Personal));
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	node->mobile_no = mobile_no;
	strcpy(node->first_name,first_name);
	strcpy(node->last_name,last_name);
	return node;
	
}

void PrintProfessional(Professional* nptr){
	if(nptr != NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("NAME : %s %s\n",nptr->first_name,nptr->last_name);
		printf("MOBILE NUMBER : %lld\n",nptr->mobile_no);
		printf("EMAIL : %s\n",nptr->email);
		printf("OFFICE NUMBER : %lld\n",nptr->office_no);
		printf("ADDRESS : %s\n",nptr->address);
		printf("INSTITUE NAME : %s\n",nptr->office);
		printf("-----------------------------------------------------------------------\n");

	}else{
		printf("-----------------------------------------------------------------------\n");
		printf("WRONG CONTACT\n");
		printf("-----------------------------------------------------------------------\n");
	}
}

void PrintPersonal(Personal* nptr){
	if(nptr != NULL){
		printf("-----------------------------------------------------------------------\n");
		printf("NAME : %s %s\n",nptr->first_name,nptr->last_name);
		printf("MOBILE NUMBER : %lld\n",nptr->mobile_no);
		printf("EMAIL : %s\n",nptr->email);
		printf("-----------------------------------------------------------------------\n");
	}else{
	printf("-----------------------------------------------------------------------\n");
		printf("WRONG CONTACT\n");
	printf("-----------------------------------------------------------------------\n");
	}
}	

Professional* newProfessional(){
	Professional* node = (Professional*)malloc(sizeof(Professional));
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	node->type = 1;
	return node;
}

Professional* newProfessional(char* first_name, char* last_name, int mobile_no){
	Professional* node = (Professional*)malloc(sizeof(Professional));
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	node->mobile_no = mobile_no;
	strcpy(node->first_name,first_name);
	strcpy(node->last_name,last_name);
	return node;
}

Personal *rightRotatePersonal(Personal *parent){
	Personal *child = parent->left;
	Personal *temp = child->right;
	child->right = parent;
	parent->left = temp;
	parent->height = max(heightPersonal(parent->left), heightPersonal(parent->right)) + 1;
	child->height = max(heightPersonal(child->left), heightPersonal(child->right)) + 1;
	return child;
}

Professional *rightRotateProfessional(Professional *parent){
	Professional *child = parent->left;
	Professional *temp = child->right;
	child->right = parent;
	parent->left = temp;
	parent->height = max(heightProfessional(parent->left), heightProfessional(parent->right)) + 1;
	child->height = max(heightProfessional(child->left), heightProfessional(child->right)) + 1;
	return child;
}

Personal *leftRotatePersonal(Personal *parent){
	Personal *child = parent->right;
	Personal *temp = child->left;
	child->left = parent;
	parent->right = temp;
	parent->height = max(heightPersonal(parent->left), heightPersonal(parent->right)) + 1;
	child->height = max(heightPersonal(child->left), heightPersonal(child->right)) + 1;
	return child;
}

Professional *leftRotateProfessional(Professional *parent){
	Professional *child = parent->right;
	Professional *temp = child->left;
	child->left = parent;
	parent->right = temp;
	parent->height = max(heightProfessional(parent->left), heightProfessional(parent->right)) + 1;
	child->height = max(heightProfessional(child->left), heightProfessional(child->right)) + 1;
	return child;
}

int getBalancePersonal(Personal *p){
	if (p == NULL)
		return 0;
	return heightPersonal(p->left) - heightPersonal(p->right);
}

int getBalanceProfessional(Professional *p){
	if (p == NULL)
		return 0;
	return heightProfessional(p->left) - heightProfessional(p->right);
}

Personal* insertPersonal(Personal* node, Personal* key){
	
	if (node == NULL)
		return key;
	
	int compare = comparePersonal(key, node);
	
	if (compare < 0)
		node->left = insertPersonal(node->left, key);
	else if (compare > 0)
		node->right = insertPersonal(node->right, key);
	else 
		return node;
		
	node->height = 1 + max(heightPersonal(node->left), heightPersonal(node->right));
	int balance = getBalancePersonal(node);
	
	if (balance > 1 && comparePersonal(key, node->left) < 0)
		return rightRotatePersonal(node);

	if (balance < -1 && comparePersonal(key, node->right) > 0)
		return leftRotatePersonal(node);

	if (balance > 1 && comparePersonal(key, node->left) > 0 ){
		node->left = leftRotatePersonal(node->left);
		return rightRotatePersonal(node);
	}

	if (balance < -1 && comparePersonal(key, node->right) < 0){
		node->right = rightRotatePersonal(node->right);
		return leftRotatePersonal(node);
	}
	
	return node;
}

Professional* insertProfessional(Professional* node, Professional* key){
	
	if (node == NULL)
		return key;
	
	int compare = compareProfessional(key, node);
	
	if (compare < 0)
		node->left = insertProfessional(node->left, key);
	else if (compare > 0)
		node->right = insertProfessional(node->right, key);
	else 
		return node;
		
	node->height = 1 + max(heightProfessional(node->left), heightProfessional(node->right));
	int balance = getBalanceProfessional(node);
	
	if (balance > 1 && compareProfessional(key, node->left) < 0)
		return rightRotateProfessional(node);

	if (balance < -1 && compareProfessional(key, node->right) > 0)
		return leftRotateProfessional(node);

	if (balance > 1 && compareProfessional(key, node->left) > 0 ){
		node->left = leftRotateProfessional(node->left);
		return rightRotateProfessional(node);
	}

	if (balance < -1 && compareProfessional(key, node->right) < 0){
		node->right = rightRotateProfessional(node->right);
		return leftRotateProfessional(node);
	}
	
	return node;
}

void addPersonal(){
	Personal* p = newPersonal();
	Personal* p1 = newPersonal();
	int change;
	char c[50];
	printf("ENTER FIRST NAME : ");
	fflush(stdin);
	gets(c);
	if(check_name(c)){
		printf("YOUR NAME IS EMPTY OR YOUR NAME CONTAIN LETTERS OTHER THAN ALPHABET....\n"
		"PRESS 1 TO CHANGE THE NAME...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER FIRST NAME : ");
			fflush(stdin);
			gets(c);
		}
	}
	strcpy(p->first_name, c);
	strcpy(p1->first_name,c);
	setName(p1->first_name);
	setName(p->first_name);
	
	printf("ENTER LAST NAME : ");
	fflush(stdin);
	gets(c);
	if(check_name(c)){
		printf("YOUR NAME IS EMPTY OR YOUR NAME CONTAIN LETTERS OTHER THAN ALPHABET....\n"
		"PRESS 1 TO CHANGE THE NAME...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER LAST NAME : ");
			fflush(stdin);
			gets(c);
		}
	}
	strcpy(p->last_name, c);
	strcpy(p1->last_name,c);
	setName(p1->last_name);
	setName(p->last_name);
	
	printf("ENTER MOBILE NUMBER : ");
	fflush(stdin);
	scanf("%lld",&(p->mobile_no));
	p1->mobile_no  = p->mobile_no;
	
	printf("ENTER EMAIL : ");
	fflush(stdin);
	gets(c);
	if(check_email(c) == 0){
		printf("YOUR EMAIL IS EMPTY OR YOUR EMAIL DOES NOT CONTAIN '@'....\n"
		"PRESS 1 TO CHANGE YOUR EMAIL...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER EMAIL : ");
			fflush(stdin);
			gets(c);
		}
	}
	strcpy(p->email, c);
	strcpy(p1->email,p->email);
	p->type = 0;
	NumberPersonal = insertNumberPersonal(NumberPersonal, p1);
	Personal_list = insertPersonal(Personal_list, p);
		
}

void DisplayPersonal(Personal* node){
	if(node == NULL)
		return ;
	DisplayPersonal(node->left);
	PrintPersonal(node);
	DisplayPersonal(node->right);
}

void addProfessional(){
	Professional* p = newProfessional();
	Professional* p1 = newProfessional();
	char c[50];
	int change;
	printf("ENTER FIRST NAME : ");
	fflush(stdin);
	gets(c);
	if(check_name(c)){
		printf("YOUR NAME IS EMPTY OR YOUR NAME CONTAIN LETTERS OTHER THAN ALPHABET....\n"
		"PRESS 1 TO CHANGE THE NAME...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER FIRST NAME : ");
			fflush(stdin);
			gets(c);
		}
	}
	strcpy(p->first_name, c);
	strcpy(p1->first_name,c);
	setName(p1->first_name);
	setName(p->first_name);
	
	printf("ENTER LAST NAME : ");
	fflush(stdin);
	gets(c);
	if(check_name(c)){
		printf("YOUR NAME IS EMPTY OR YOUR NAME CONTAIN LETTERS OTHER THAN ALPHABET....\n"
		"PRESS 1 TO CHANGE THE NAME...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER LAST NAME : ");
			fflush(stdin);
			gets(c);
		}
	}
	strcpy(p1->last_name,c);
	strcpy(p->last_name, c);
	setName(p->last_name);
	setName(p1->last_name);
	
	printf("ENTER MOBILE NUMBER : ");
	fflush(stdin);
	scanf("%lld",&(p->mobile_no));
	p1->mobile_no = p->mobile_no;
	
	printf("ENTER EMAIL : ");
	fflush(stdin);
	gets(c);
	if(check_email(c) == 0){
		printf("YOUR EMAIL IS EMPTY OR YOUR EMAIL DOES NOT CONTAIN '@'....\n"
		"PRESS 1 TO CHANGE YOUR EMAIL...\n");
		fflush(stdin);
		scanf("%d",&change);
		if(change == 1){
			printf("ENTER EMAIL : ");
			fflush(stdin);
			gets(c);
		}
	}	
	strcpy(p->email, c);
	strcpy(p1->email,c);
	
	printf("ENTER OFFICE NUMBER : ");
	fflush(stdin);
	scanf("%lld",&(p->office_no));
	p1->office_no = p->office_no;
	
	printf("ENTER INSTITUTE NAME : ");
	fflush(stdin);
	gets(c);
	strcpy(p->office, c);
	strcpy(p1->office,c);
	
	printf("ENTER ADDRESS : ");
	fflush(stdin);
	gets(c);
	strcpy(p->address, c);
	strcpy(p1->address,c);
	p->type = 1;
	NumberProfessional = insertNumberProfessional(NumberProfessional, p1);
	Professional_list = insertProfessional(Professional_list,p);

		
}

void DisplayProfessional(Professional* node){
	if(node == NULL)
		return ;
	DisplayProfessional(node->left);
	PrintProfessional(node);
	DisplayProfessional(node->right);
	
}

Personal* SearchPersonalName(Personal* node, Personal* key){
	if (node == NULL)
		return NULL;
	
	Personal* p;
	int compare = comparePersonalName(key, node);
	if (compare < 0)
		p = SearchPersonalName(node->left, key);
	else if (compare > 0)
		p = SearchPersonalName(node->right, key);
	else 
		p = node;
		
	return p;
}

Professional* SearchProfessionalName(Professional* node, Professional* key){
	if (node == NULL)
		return NULL;
	
	Professional* p;
	int compare = compareProfessionalName(key, node);
	if (compare < 0)
		p = SearchProfessionalName(node->left, key);
	else if (compare > 0)
		p = SearchProfessionalName(node->right, key);
	else 
		p = node;
		
	return p;
}

Professional* SearchProfessionalNumber(Professional* node, Professional* key){
	if (node == NULL)
		return NULL;
	Professional* p;
	if (node->mobile_no > key->mobile_no)
		p = SearchProfessionalNumber(node->left, key);
	else if (key->mobile_no > node->mobile_no)
		p = SearchProfessionalNumber(node->right, key);
	else 
		p = node;
	
	return p;
}

Personal* SearchPersonalNumber(Personal* node, Personal* key){
	if (node == NULL)
		return NULL;
	Personal* p;
	if (node->mobile_no > key->mobile_no)
		p = SearchPersonalNumber(node->left, key);
	else if (key->mobile_no > node->mobile_no)
		p = SearchPersonalNumber(node->right, key);
	else 
		p = node;
	
	return p;
}

void searchContact(){
		printf("SEARCH CONTACT : \n");
			printf("-----------------------------------------------------------------------\n");
			int change;
			Personal* p = newPersonal();
			Professional* p1 = newProfessional();
			char c[50];
			printf("ENTER 1 TO SEARCH BY NAME OR ENTER 0 TO SEARCH BY NUMBER:\n");
			scanf("%d",&change);
			printf("-----------------------------------------------------------------------\n");
			if(change == 1){
				printf("ENTER FIRST NAME : ");
				fflush(stdin);
				gets(c);
				strcpy(p->first_name, c);
				strcpy(p1->first_name,c);
				printf("-----------------------------------------------------------------------\n");
		
				printf("ENTER LAST NAME : ");
				fflush(stdin);
				gets(c);
				strcpy(p->last_name, c);
				strcpy(p1->last_name,c);
				printf("-----------------------------------------------------------------------\n");
				p = SearchPersonalName(Personal_list, p);
				
				if(p == NULL){
					p1 = SearchProfessionalName(Professional_list, p1);
					if(p1 == NULL)
						printf("CONTACT NOT PRESENT!!!..\n");
					else
						PrintProfessional(p1);
				}
				else
					PrintPersonal(p);
				
				}else{
					printf("ENTER MOBILE NUMBER : ");
					fflush(stdin);
					scanf("%lld",&(p->mobile_no));
					p1->mobile_no = p->mobile_no;
					printf("-----------------------------------------------------------------------\n");
					p = SearchPersonalNumber(NumberPersonal, p);
					if(p == NULL){
						p1 = SearchProfessionalNumber(NumberProfessional, p1);
						if(p1 == NULL)
							printf("CONTACT NOT PRESENT!!!..\n");
						else
							PrintProfessional(p1);
					}
					else
						PrintPersonal(p);
					}	
}

Personal * minValuePersonal(Personal* node){
    Personal* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
 	
    return curr;
}

void CopyPersonal(Personal* root,Personal* key){
	strcpy(root->first_name, key->first_name);
	strcpy(root->last_name, key->last_name);
	strcpy(root->email, key->email);
	root->mobile_no = key->mobile_no;
}

Personal* DeletePersonal(Personal* root,Personal* key){
	 
    if (root == NULL)
        return root;
        
 	int compare = comparePersonal(key, root);
 	
    if ( compare < 0 )
        root->left = DeletePersonal(root->left, key);
    else if( compare > 0 )
        root->right = DeletePersonal(root->right, key);
    else{
        if( (root->left == NULL) || (root->right == NULL) ){
            Personal *temp = root->left ? root->left : root->right;
 
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
            	Personal* p = root;
            	root = temp;
				temp = p; 
			}
            
			free(temp);
        }
        else{
        	Personal* temp = minValuePersonal(root->right);
            CopyPersonal(root, temp);
            root->right = DeletePersonal(root->right,temp);
        }
    }
 
    if (root == NULL)
    return root;
 
    root->height = 1 + max(heightPersonal(root->left), heightPersonal(root->right));
 
    int balance = getBalancePersonal(root);
 
    if (balance > 1 && comparePersonal(key, root->left) < 0)
		return rightRotatePersonal(root);

	if (balance < -1 && comparePersonal(key, root->right) > 0)
		return leftRotatePersonal(root);

	if (balance > 1 && comparePersonal(key, root->left) > 0 ){
		root->left = leftRotatePersonal(root->left);
		return rightRotatePersonal(root);
	}

	if (balance < -1 && comparePersonal(key, root->right) < 0){
		root->right = rightRotatePersonal(root->right);
		return leftRotatePersonal(root);
	}
	
 
    return root; 
}

void editContact(){
	Personal* p = newPersonal();
	Professional* p1 = newProfessional();
	char c[50];
	
	printf("EDIT CONTACT : \n");
	printf("ENTER FIRST NAME : ");
	fflush(stdin);
	gets(c);
	setName(c);
	strcpy(p->first_name, c);
	strcpy(p1->first_name,c);
	
	printf("ENTER LAST NAME : ");
	fflush(stdin);
	gets(c);
	setName(c);
	strcpy(p->last_name, c);
	strcpy(p1->last_name,c);
	
	printf("ENTER MOBILE NUMBER : ");
	fflush(stdin);
	scanf("%lld",&(p->mobile_no));
	p1->mobile_no = p->mobile_no;
	
	p = SearchPersonalName(Personal_list, p);		
			
	if(p == NULL)
		p1 = SearchProfessionalName(Professional_list, p1);
	else{
		printf("MIL GAYA\n");
		Personal* new_modify = newPersonal();
		CopyPersonal(new_modify,p);
		Personal_list = DeletePersonal(Personal_list, p);
		int t = 1;
		char modified_content[50];
		while(t != 0){
	printf(
	"|--------------------------------------------------------|\n"
	"|ENTER |          FUNCTION TO BE PERFORMED               |\n"
	"|--------------------------------------------------------|\n"
	"|  0   | 			  TO BREAK THE LOOP                   |\n"
    "|  1   | 			  TO MODIFY NAME                      |\n"
	"|  2   |  			  TO MODIFY MOBILE NUMBER             |\n"
	"|  3   | 			  TO MODIFY EMAIL                     |\n"
	"|______|_________________________________________________|\n");
			scanf("%d",&t);
	      	
			if(t == 1){
				fflush(stdin);
				printf("ENTER FIRST NAME : ");
				gets(modified_content);
				setName(modified_content);
				strcpy(new_modify->first_name,modified_content);
				
				fflush(stdin);
				printf("ENTER LAST NAME : ");
				gets(modified_content);
				setName(modified_content);
				
				strcpy(new_modify->last_name,modified_content);
				
			}else if(t == 2){
				printf("ENTER MOBILE NUMBER : ");
				fflush(stdin);				
				scanf("%lld",&(p->mobile_no));
			
			}else if(t == 3){
				printf("ENTER EMAIL : ");
				fflush(stdin);
				gets(modified_content);
				strcpy(new_modify->email,modified_content);
				
			}
		}
		Personal_list =  insertPersonal(Personal_list,new_modify);		
	}
		
		
}

Professional* minValueProfessional(Professional* node){
    Professional* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
 	
    return curr;
}

void CopyProfessional(Professional* root,Professional* key){
	strcpy(root->first_name, key->first_name);
	strcpy(root->last_name, key->last_name);
	strcpy(root->email, key->email);
	strcpy(root->address,key->address);
	strcpy(root->office,key->office);
	root->office_no = key->office_no;
	root->mobile_no = key->mobile_no;
}

Professional* DeleteProfessional(Professional* root,Professional* key){
	 
    if (root == NULL)
        return root;
        
 	int compare = compareProfessional(key, root);
 	
    if ( compare < 0 )
        root->left = DeleteProfessional(root->left, key);
    else if( compare > 0 )
        root->right = DeleteProfessional(root->right, key);
    else{
        if( (root->left == NULL) || (root->right == NULL) ){
            Professional *temp = root->left ? root->left : root->right;
 
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
            	Professional* p = root;
            	root = temp;
				temp = p; 
			}
            
			free(temp);
        }
        else{
        	Professional* temp = minValueProfessional(root->right);
            CopyProfessional(root, temp);
            root->right = DeleteProfessional(root->right,temp);
        }
    }
 
    if (root == NULL)
    return root;
 
    root->height = 1 + max(heightProfessional(root->left), heightProfessional(root->right));
 
    int balance = getBalanceProfessional(root);
 
    if (balance > 1 && compareProfessional(key, root->left) < 0)
		return rightRotateProfessional(root);

	if (balance < -1 && compareProfessional(key, root->right) > 0)
		return leftRotateProfessional(root);

	if (balance > 1 && compareProfessional(key, root->left) > 0 ){
		root->left = leftRotateProfessional(root->left);
		return rightRotateProfessional(root);
	}

	if (balance < -1 && compareProfessional(key, root->right) < 0){
		root->right = rightRotateProfessional(root->right);
		return leftRotateProfessional(root);
	}
    return root; 
}

Personal* insertNumberPersonal(Personal* node, Personal* key){
	
	if (node == NULL)
		return key;
	
	if (node->mobile_no > key->mobile_no)
		node->left = insertNumberPersonal(node->left, key);
	else if (node->mobile_no < key->mobile_no )
		node->right = insertNumberPersonal(node->right, key);
	else 
		return node;
		
	node->height = 1 + max(heightPersonal(node->left), heightPersonal(node->right));
	int balance = getBalancePersonal(node);
	
	if (balance > 1 && node->mobile_no > key->mobile_no)
		return rightRotatePersonal(node);

	if (balance < -1 && node->mobile_no < key->mobile_no)
		return leftRotatePersonal(node);

	if (balance > 1 && node->mobile_no < key->mobile_no ){
		node->left = leftRotatePersonal(node->left);
		return rightRotatePersonal(node);
	}

	if (balance < -1 && node->mobile_no > key->mobile_no){
		node->right = rightRotatePersonal(node->right);
		return leftRotatePersonal(node);
	}
	
	return node;
}

Professional* insertNumberProfessional(Professional* node, Professional* key){
	
	if (node == NULL)
		return key;
	
	if (node->mobile_no > key->mobile_no)
		node->left = insertNumberProfessional(node->left, key);
	else if (node->mobile_no < key->mobile_no )
		node->right = insertNumberProfessional(node->right, key);
	else 
		return node;
		
	node->height = 1 + max(heightProfessional(node->left), heightProfessional(node->right));
	int balance = getBalanceProfessional(node);
	
	if (balance > 1 && node->mobile_no > key->mobile_no)
		return rightRotateProfessional(node);

	if (balance < -1 && node->mobile_no < key->mobile_no)
		return leftRotateProfessional(node);

	if (balance > 1 && node->mobile_no < key->mobile_no ){
		node->left = leftRotateProfessional(node->left);
		return rightRotateProfessional(node);
	}

	if (balance < -1 && node->mobile_no > key->mobile_no){
		node->right = rightRotateProfessional(node->right);
		return leftRotateProfessional(node);
	}
	
	return node;
}

void DisplayDescendingPersonal(Personal* p){
	if(p == NULL)
		return ;
	DisplayDescendingPersonal(p->right);
	PrintPersonal(p);
	DisplayDescendingPersonal(p->left);
}

void DisplayDescendingProfessional(Professional* p){
	if(p == NULL)
		return ;
		
	DisplayDescendingProfessional(p->right);
	PrintProfessional(p);
	DisplayDescendingProfessional(p->left);
}

void RangeSearchPersonal(Personal *root, ll k1, ll k2){
    if ( NULL == root )
        return;
     
    if ( k1 < root->mobile_no )
        RangeSearchPersonal(root->left, k1, k2);
     
    if ( k1 <= root->mobile_no && k2 >= root->mobile_no )
        PrintPersonal(root);
        
   RangeSearchPersonal(root->right, k1, k2);
}

void RangeSearchProfessional(Professional *root, ll k1, ll k2){
    if ( NULL == root )
        return;
     
    if ( k1 < root->mobile_no )
        RangeSearchProfessional(root->left, k1, k2);
     
    if ( k1 <= root->mobile_no && k2 >= root->mobile_no )
        PrintProfessional(root);
        
   RangeSearchProfessional(root->right, k1, k2);
}

void cleanHeap(){
	
}
int main(){
	Personal_list = NULL;
	Professional_list = NULL;
	NumberPersonal = NULL;
	NumberProfessional = NULL;
	Personal* p;
	int total_contact, n, loop = 1;
	
	while(loop){
	printf(
	"|--------------------------------------------------------\n"
	"|ENTER |\tFUNCTION TO BE PERFORMED                      \n"
	"|--------------------------------------------------------\n"
    "|  1   |\tTO ADD CONTACT                                \n"
	"|  2   |\tTO SEARCH CONTACT                             \n"
	"|  3   |\tTO EDIT A CONTACT	                          \n"
	"|  4   |\tTO DISPLAY CONTACT	                          \n"
	"|  5   |\tTO DELETE A CONTACT 	                      \n"
	"|  6   |\tTO SORT ACCORDING NUMBER                      \n"
	"|  7   |\tRANGE SEARCH                                  \n"
	"|______|_________________________________________________\n");
		printf("-----------------------------------------------------------------------\n");	
		scanf("%d",&n);
		printf("-----------------------------------------------------------------------\n");
		
		if(n == 1){
			int t;
			printf("ADD CONTACT: \n");
			printf("-----------------------------------------------------------------------\n");
			printf("ENTER 1 TO ADD CONTACT IN PROFESSIONAL LIST AND ENTER 0 TO ADD CONTACT IN PERSONAL LIST: \n");
			scanf("%d",&t);
			fflush(stdin);
			printf("-----------------------------------------------------------------------\n");
			printf("ENTER THE NUMBER OF CONTACT TO BE ADDED: ");
			scanf("%d",&total_contact);
			printf("-----------------------------------------------------------------------\n");
			if(t == 1){
				while(total_contact--){
					printf("-----------------------------------------------------------------------\n");
					addProfessional();	
					printf("-----------------------------------------------------------------------\n");
				}
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NAME: \n");
				DisplayProfessional(Professional_list);
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NUMBER:\n");	
				DisplayProfessional(NumberProfessional);		
			}else{
				while(total_contact--){
					printf("-----------------------------------------------------------------------\n");
					addPersonal();
					printf("-----------------------------------------------------------------------\n");
				}
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NAME: \n");
				DisplayPersonal(Personal_list);
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NUMBER:\n");	
				DisplayPersonal(NumberPersonal);
				
			}
		}else if(n == 2){
			printf("SEARCH CONTACT: \n");
			printf("-----------------------------------------------------------------------\n");
			searchContact();
		}
		else if(n == 3){
			printf("EDIT CONTACT:\n");
			editContact();	
			printf("-----------------------------------------------------------------------\n");
			
		}else if(n == 4){
			printf("DISPLAY:\n");
			printf("-----------------------------------------------------------------------\n");
			int t;
			printf("ENTER 1 TO DISPLAY PERSONAL LIST OR ENTER 0 TO DISPLAY PROFESSIONAL:\n");
			scanf("%d",&t);
			printf("-----------------------------------------------------------------------\n");

			if(t == 1){
				printf("ENTER 1 TO DISPLAY IN ASCENDING ORDER OR ENTER 0 TO DISPLAY IN DESCENDING ORDER:\n");
				scanf("%d",&t);
				printf("-----------------------------------------------------------------------\n");
		
				if(t == 1){
					if(Personal_list == NULL)
						printf("PERSONAL LIST IS EMPTY\n");
					else
						DisplayPersonal(Personal_list);
			
					if(NumberPersonal == NULL)
						printf("NUMBER PERSONAL LIST IS EMPTY\n");
					else
						DisplayPersonal(NumberPersonal);	
					
				}else{
					if(Personal_list == NULL)
						printf("PERSONAL LIST IS EMPTY\n");
					else
						DisplayDescendingPersonal(Personal_list);
					
					if(NumberPersonal == NULL)
						printf("NUMBER PERSONAL LIST IS EMPTY\n");
					else
						DisplayDescendingPersonal(NumberPersonal);
				}
				printf("-----------------------------------------------------------------------\n");
				
			}else{
				printf("-----------------------------------------------------------------------\n");
				
				printf("ENTER 1 TO DISPLAY IN ASCENDING ORDER OR ENTER 0 TO DISPLAY IN DESCENDING ORDER:\n");
				scanf("%d",&t);
				printf("-----------------------------------------------------------------------\n");
				if(t == 1){
					if(Professional_list == NULL)
						printf("PROFESSIONAL LIST IS EMPTY\n");
					else
						DisplayProfessional(Professional_list);
						
					if(NumberProfessional == NULL)
						printf("NUMBER PROFESSIONAL LIST IS EMPTY\n");
					else
						DisplayProfessional(NumberProfessional);	
						
				}else{
					if(Professional_list == NULL)
						printf("PROFESSIONAL LIST IS EMPTY\n");
					else
						DisplayProfessional(Professional_list);
						
					if(NumberProfessional == NULL)
						printf("NUMBER PROFESSIONAL LIST IS EMPTY\n");
					else
						DisplayProfessional(NumberProfessional);	
					
				}
				printf("-----------------------------------------------------------------------\n");
					
			}
		}else if(n == 5){
				printf("DELETE CONTACT:\n");
				printf("-----------------------------------------------------------------------\n");
				int t;
				printf("ENTER 1 FOR PERSONAL LIST OR 0 FOR PROFESSIONAL LIST\n");
				scanf("%d",&t);
				printf("-----------------------------------------------------------------------\n");
				
				if(t == 1){
					Personal* p = newPersonal();
					printf("ENTER FIRST NAME: \n");
					fflush(stdin);
					gets(p->first_name);
					printf("ENTER LAST NAME:\n");
					fflush(stdin);
					gets(p->last_name);
					printf("ENTER MOBILE NUMBER:\n");
					fflush(stdin);
					scanf("%lld",&(p->mobile_no));
					Personal_list = DeletePersonal(Personal_list, p);
				}else{
					Professional* p = newProfessional();
					printf("ENTER FIRST NAME: \n");
					fflush(stdin);
					gets(p->first_name);
					printf("ENTER LAST NAME:\n");
					fflush(stdin);
					gets(p->last_name);
					printf("ENTER MOBILE NUMBER:\n");
					fflush(stdin);
					scanf("%lld",&(p->mobile_no));
					Professional_list = DeleteProfessional(Professional_list, p);
				}
				printf("-----------------------------------------------------------------------\n");
				
		}else if(n == 6){
			
			int t;
			printf("ENTER 1 FOR PERSONAL CONTACT OR 0 FOR PROFESSIONAL LIST:\n");
			scanf("%d",&t);
			printf("-----------------------------------------------------------------------\n");
				
			if(t == 1){
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NUMBER:\n");	
				DisplayPersonal(NumberPersonal);	
			}else{
				printf("-----------------------------------------------------------------------\n");
				printf("LIST ARRANGED ACCORDING TO NUMBER:\n");	
				DisplayProfessional(NumberProfessional);
			}
			printf("-----------------------------------------------------------------------\n");
		}else if(n == 7){
		printf("RANGE SEARCH:\n");
		printf("-----------------------------------------------------------------------\n");
		int t;
		printf("ENTER 1 FOR PERSONAL LIST OR 0 FOR PROFESSIONAL LIST:\n");
		scanf("%d",&t);
		if(t == 1){
			ll no1, no2;
			printf("ENTER FIRST NUMBER:\n");
			scanf("%d",&no1);
			printf("ENTER LAST NUMBER:\n");
			scanf("%d",&no2);
			RangeSearchPersonal(NumberPersonal,no1,no2);
		}else{
			ll no1, no2;
			printf("ENTER FIRST NUMBER:\n");
			scanf("%d",&no1);
			printf("ENTER LAST NUMBER:\n");
			scanf("%d",&no2);
			RangeSearchProfessional(NumberProfessional,no1,no2);
		}
	}
		
		printf("ENTER 0 TO BREAK THE LOOP : \n");	
		scanf("%d",&loop);
		printf("-----------------------------------------------------------------------\n");
	}
	return 0;
}
