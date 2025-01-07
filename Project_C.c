#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<windows.h>
#include<ctype.h>

struct Date {
    int day, month, year;
};
struct Student {
    char student_id[10];
    char classroom[10];
    char name[50];
    struct Date date;
    bool gender;
    char email[20];
    char phone[20];
    int number_course;
};
struct Teacher {
    char teacher_id[10];
    char name[50];
    struct Date birth;
    bool gender;
    char email[30];
    char phone[20];
    int class_number;
};
struct Classroom {
    char class_id[10];
    char class_name[10];
    char teacher_id[10];
    char teacher_name[50];
    int student_number;//////
};
int n=5;
struct Student students[100] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789", 3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", 1}
};
int t=5;
struct Teacher teachers[50] = {
   {"11", "Tran Van C", {12, 3, 1988}, true, "TVC@gmail.com", "0123647821",4},
   {"12", "Tran Thi N", {12, 3, 1989}, false, "TTN@gmail.com", "0234858997", 5},
   {"13", "Tran Van H", {25, 10, 1991}, true, "TVH@gmail.com", "01478529632", 1},
   {"14", "Tran Thi D", {14, 5, 2000}, false, "TTD@gmail.com", "02653415999", 3},
   {"15", "Tran Van P", {30, 12, 1995}, true, "TVP@gmail.com", "01985648822", 6}//soluonglop
    //"No class" ??
 };
int c=4;
struct Classroom classrooms[50] = {
    {"A1", "ENG_A", "11", "Tran Van C", 10},
    {"A2", "ENG_B", "12", "Tran Thi N", 7},    
	{"A3", "ENG_C", "13", "Tran Van H", 3},
    {"A4", "ENG_D", "14", "Tran Thi D", 5}//soluongsinhvien
 };
void printSlowly(const char *mes, int delay){
	int i;
	for(i = 0; mes[i] != '\0'; i++){
		printf("%c",mes[i]);
		fflush(stdout);
		Sleep(delay);
	}
}
void menuStart(int *menu){
    do {
        printf("\n Student Management System Using C \n");
        printf("\n\t    CHOOSE YOUR ROLE\n");
        printf("\t=======================\n");
        printf("\t[1] Student.\n");
        printf("\t[2] Teacher.\n");
        printf("\t[3] Classroom.\n");
        printf("\t[4] Admin.\n");
		printf("\t[5] Exit the Program.\n");
        printf("\n\tEnter your choice: ");
        if (scanf("%d", menu) != 1) {
            printSlowly("Invalid input \n",50);
			printSlowly("!!!\n",150);
            exit(1);
        }
    } while (*menu < 1 || *menu > 5);
}
void studentMenu(){
	printf("\n\t      Student Menu \n");
	printf("\t=============================\n");
    printf("\t[1]. Show student list\n");
    printf("\t[2]. Add a new student\n");
    printf("\t[3]. Edit student information\n");
    printf("\t[4]. Search a student by name\n");
    printf("\t[5]. Sort a student by name\n");
    printf("\t[6]. Delete a student by name\n");
    printf("\t[7] Exit\n");
    printf("\n\tEnter your choice: ");
}
void teacherMenu(){
	printf("\n\t      Teacher Menu \n");
	printf("\t=============================\n");
    printf("\t[1]. Show teacher list\n");
    printf("\t[2]. Add a new teacher\n");
    printf("\t[3]. Edit teacher information\n");
    printf("\t[4]. Search a teacher by name\n");
    printf("\t[5]. Sort a teacher by name\n");
    printf("\t[6]. Delete a teacher by name\n");
    printf("\t[7] Exit\n");
    printf("\n\tEnter your choice: ");
}
void classMenu(){
	printf("\n\t     Classroom Menu \n");
	printf("\t=============================\n");
    printf("\t[1]. Show classroom list\n");
    printf("\t[2]. Add a new classroom\n");
    printf("\t[3]. Edit classroom information\n");
    printf("\t[4]. Sort a classroom by name\n");
    printf("\t[5]. Delete a classroom by name\n");
	printf("\t[6]. Add classroom by a teacher\n");/////dg phat trien
    printf("\t[7] Exit\n");
    printf("\n\tEnter your choice: ");
}
void col_s() {
    printf("\n|==========================================================================================================|\n");
    printf("| ID | Classroom | Name               | Birthdate  | Gender  | Email             | Phone         | Courses |\n");
    printf("|====|===========|====================|============|=========|===================|===============|=========|\n");
}
void infor_s(struct Student students[], int i) {
        printf("| %-2s | %-9s | %-18s | %02d/%02d/%04d | %-7s | %-17s | %-13s | %-7d |\n",
               students[i].student_id,
               students[i].classroom,
               students[i].name,
               students[i].date.day,
               students[i].date.month,
               students[i].date.year,
               students[i].gender ? "Male" : "Female",
               students[i].email,
               students[i].phone,
               students[i].number_course);
}
void row_s(){
    printf("|----------------------------------------------------------------------------------------------------------|\n");
}
void col_t(){
    printf("|=====================================================================================================================|\n");
    printf("| ID       | Name                | Birthdate   | Gender  | Email                     | Phone           | Class Number |\n");
    printf("|==========|=====================|=============|=========|===========================|=================|==============|\n");
}
void infor_t(struct Teacher teachers[], int i) {
    printf("| %-8s | %-19s | %02d/%02d/%04d  | %-6s  | %-25s | %-15s | %-12d |\n",
           teachers[i].teacher_id,
           teachers[i].name,
           teachers[i].birth.day,
           teachers[i].birth.month,
           teachers[i].birth.year,
           teachers[i].gender ? "Male" : "Female",
           teachers[i].email,
           teachers[i].phone,
           teachers[i].class_number); 
}
void row_t() {
    printf("|=====================================================================================================================|\n");
}
void col_c() {
    printf("|=================================================================================|\n");
    printf("| Class ID  | Class Name       | Teacher ID   | Teacher Name       | Students     |\n");
    printf("|===========|==================|==============|====================|==============|\n");
}
void infor_c(struct Classroom classrooms[], int i) {
        printf("| %-9s | %-16s | %-12s | %-19s| %-12d |\n",
               classrooms[i].class_id,
               classrooms[i].class_name,
               classrooms[i].teacher_id,
               classrooms[i].teacher_name,
               classrooms[i].student_number);
}
void row_c() {
    printf("|=================================================================================|\n");
}
void save_file_s(struct Student students[], int *n){
	FILE *file = fopen("students.dat","wb");
	if(file == NULL){
		printf("\n\tNot open file students.dat ^ ^ \n");
		return;
	}
	fwrite(n,sizeof(int),1,file);
	fwrite(students, sizeof(struct Student), *n, file);
	fclose(file);
	printf("\n\tData has been read from the file students.dat successfully ^ ^\n");
}
void save_file_t(struct Teacher teachers[], int *t){
	FILE *file = fopen("teachers.dat","wb");
	if(file == NULL){
		printf("\n\tNot open file teachers.dat ^ ^ \n");
		return;
	}
	fwrite(t,sizeof(int),1,file);
	fwrite(students, sizeof(struct Teacher), *t, file);
	fclose(file);
	printf("\n\tData has been read from the file teachers.dat successfully ^ ^\n");
}
void save_file_c(struct Classroom classrooms[], int *c){
	FILE *file = fopen("classrooms.dat","wb");
	if(file == NULL){
		printf("\n\tNot open file classrooms.dat ^ ^ \n");
		return;
	}
	fwrite(c,sizeof(int),1,file);
	fwrite(classrooms, sizeof(struct Classroom), *c, file);
	fclose(file);
	printf("\n\tData has been recorded from the file classrooms.dat successfully ^ ^\n");
}
void read_file_s(struct Student students[], int *n){
	FILE *file = fopen("students.dat","rb");
	if(file == NULL){
		printf("\n\tNot open file students.dat ^ ^\n");
		return;
	}
	fread(n, sizeof(int), 1, file);
	fread(students, sizeof(struct Student), *n, file);
	fclose(file);
    printf("\n\tData has been read from the file students.dat successfully ^ ^\n");
}

void read_file_t(struct Teacher teachers[], int *t){
	FILE *file = fopen("teachers.dat","rb");
	if(file == NULL){
		printf("\n\tNot open file teachers.dat ^ ^\n");
		return;
	}
	fread(t, sizeof(int), 1, file);
	fread(teachers, sizeof(struct Teacher), *t, file);
	fclose(file);
    printf("\n\tData has been read from the file teachers.dat successfully ^ ^\n");
}
void read_file_c(struct Classroom classrooms[], int *c){
	FILE *file = fopen("classrooms.dat","rb");
	if(file == NULL){
		printf("\n\tNot open file classrooms.dat ^ ^");
		return;
	}
	fread(c, sizeof(int), 1, file);
	fread(classrooms, sizeof(struct Classroom), *c, file);
	fclose(file);
    printf("\n\tData has been read from the file classrooms.dat successfully ^ ^\n");
}
void show_student_list(struct Student students[], int n) {
    if (n <= 0) {
        printf("\n\t\t\t\t\t No Students Found \n");
        return;
    }
    printf("\n\t\t\t\t\t All Students List \n");
    printf("\n");
    col_s();
    int i;
    for(i = 0; i < n; i++){
    	infor_s(students,i);
	}
	row_s();
}
void show_teacher_list(struct Teacher teachers[], int *t) {
	if (*t <= 0) {
		printf("\n\t\t\t\t\t No Teacher Found \n");
		return;
	}
	printf("\n\t\t\t\t\t All Teacher List \n");
	printf("\n");
	col_t();
	int i;
	for(i = 0; i < *t; i++){
		infor_t(teachers,i);
	}
	row_t();
}
void show_class_list(struct Classroom classrooms[], int c) {
	if (c <= 0) {
		printf("\n\t\t\t\t\t No Classroom Found \n");
		return;
	}
	printf("\n\t\t\t\t\t All Classroom List \n");
	printf("\n");
	col_c();
	int i;
	for(i = 0; i < c; i++){
		infor_c(classrooms,i);
	}
	row_c();
}
bool valid_date(int day, int month, int year) {
    if (year < 1900 || year > 2030 || month < 1 || month > 12){
		return false;
	}
	if(month==2){
		int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)?29:28;
		if(day>=1&&day<=leap_year){
		return true;
		}
	}else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
		if(day>=1 || day<=31){
			return true;
		}
	}else{
		if(day>=1 || day<=30){
			return true;
		}
	}
	return false;
}
void addStudent(struct Student students[], int *n) {
    if (*n >= 100) {
        printf("Error: Max student limit reached (100 students).\n");
        return;
    }
    struct Student new_student;
    while (1) {
        int id = 0;
        printf("\n\tInput ID: ");
        fflush(stdin);
        fgets(new_student.student_id, sizeof(new_student.student_id), stdin);
        new_student.student_id[strcspn(new_student.student_id, "\n")] = '\0';
        if (strlen(new_student.student_id) == 0) {
            printf("\nError: ID cannot be empty.\n");
        } else if (strlen(new_student.student_id) > 9) {
            printf("\nError: ID cannot exceed 9 characters.\n");
        } else {
        	int i;
            for (i = 0; i < *n; i++) {
                if (strcmp(new_student.student_id, students[i].student_id) == 0) {
                    id = 1;
                    printSlowly("\n\tError: ID duplicate\n", 70);
                    printSlowly("\t  Please input a different ID",70);
                    printSlowly("^ ^",110);
                    break;
                }
            }
            if (!id) {
                break;
            }
        }
    }
    while (1) {
        printf("\tInput classroom: ");
        fflush(stdin);
        fgets(new_student.classroom, sizeof(new_student.classroom), stdin);
        new_student.classroom[strcspn(new_student.classroom, "\n")] = '\0';
        if (strlen(new_student.classroom) == 0) {
            printf("Error: Classroom cannot be empty.\n");
        } else if (strlen(new_student.classroom) > 10) {
            printf("Error: Classroom cannot exceed 10 characters.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput name: ");
        fgets(new_student.name, sizeof(new_student.name), stdin);
        new_student.name[strcspn(new_student.name, "\n")] = '\0';
        if (strlen(new_student.name) == 0) {
            printf("Error: Name cannot be empty.\n");
        } else if (strlen(new_student.name) > 49) {
            printf("Error: Name cannot exceed 49 characters.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput birthdate (day/month/year): ");
        if (scanf("%d/%d/%d", &new_student.date.day, &new_student.date.month, &new_student.date.year) != 3) {
            printf("\n\t\tError: Invalid date format\n");
            while (getchar() != '\n');
        } else if (!valid_date(new_student.date.day, new_student.date.month, new_student.date.year)) {
            printf("\n\t\tError: Invalid date\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput gender (1 for Male, 0 for Female): ");
        if (scanf("%d", &new_student.gender) != 1 || (new_student.gender != 0 && new_student.gender != 1)) {
            printf("Error: Gender must be 1 (Male) or 0 (Female).\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput email (without @gmail.com): ");
        getchar();
        fgets(new_student.email, sizeof(new_student.email), stdin);
        new_student.email[strcspn(new_student.email, "\n")] = '\0';
        if (strlen(new_student.email) == 0) {
            printf("\n\t\tError: Email cannot be empty.\n");
        } else if (strlen(new_student.email) > 14) { 
            printf("\n\t\tError: Email prefix cannot exceed 14 characters.\n");
        } else {
            strcat(new_student.email, "@gmail.com");
            break;
        }
    }
    while (1) {
        printf("\tInput phone: ");
        fgets(new_student.phone, sizeof(new_student.phone), stdin);
        new_student.phone[strcspn(new_student.phone, "\n")] = '\0';
        if (strlen(new_student.phone) == 0) {
            printf("\n\t\tError: Phone number cannot be empty.\n");
        } else if (strlen(new_student.phone) > 19) {
            printf("\n\t\tError: Phone number cannot exceed 19 characters.\n");
        } else if (strspn(new_student.phone, "0123456789") != strlen(new_student.phone)) {
            printf("\n\t\tError: Phone number must contain only digits.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput number of courses: ");
        if (scanf("%d", &new_student.number_course) != 1 || new_student.number_course < 0) {
            printf("\n\t\tError: Number of courses must be a positive integer.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    students[*n] = new_student;
    (*n)++;
    printf("\n\tStudent added successfully ^ ^\n");
    printf("\n\tNew Student Information:\n");
    col_s();
    infor_s(students, *n - 1);
    row_s();
}
void editStudent() {
    if (n <= 0) {
        printf("\n\tNo student data to edit ^ ^\n");
        return;
    }
    char student_id[20];
    printf("\nEnter the ID of the student to edit: ");
    scanf("%s", student_id);
    printf("\n");
    getchar();
    int found = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Student with ID %s not found.\n", student_id);
        return;
    }
    printf("\nEditing information for student ID: %s\n", student_id);
    while (1) {
        printf("\tClassroom (current: %s): ", students[found].classroom);
        char temp_classroom[11];
        fgets(temp_classroom, sizeof(temp_classroom), stdin);
        temp_classroom[strcspn(temp_classroom, "\n")] = '\0';
        if (strlen(temp_classroom) > 0 && strlen(temp_classroom) <= 10) {
            strcpy(students[found].classroom, temp_classroom);
            break;
        } else {
            printSlowly("\n\t\tError: Classroom must be 1-10 characters\n",100);
        }
    }
    while (1) {
        printf("\tName (current: %s): ", students[found].name);
        char temp_name[50];
        fgets(temp_name, sizeof(temp_name), stdin);
        temp_name[strcspn(temp_name, "\n")] = '\0';
        if (strlen(temp_name) > 0 && strlen(temp_name) <= 49) {
            strcpy(students[found].name, temp_name);
            break;
        } else {
            printSlowly("\n\tError: Name cannot exceed 49 characters\n",70);
            printSlowly(" ^ ^",120);
        }
    }
    while (1) {
        printf("\tBirthdate (day/month/year) (current: %02d/%02d/%04d): ",
               students[found].date.day, students[found].date.month, students[found].date.year);
        int day, month, year;
        if (scanf("%d/%d/%d", &day, &month, &year) == 3 &&
            day >= 1 && day <= 31 &&
            month >= 1 && month <= 12 &&
            year >= 1900 && year <= 2030) {
            students[found].date.day = day;
            students[found].date.month = month;
            students[found].date.year = year;
            break;
        }
        printf("\n\tError: Invalid date\n");
        getchar();
    }
    while (1) {
        printf("\tGender (1 for Male, 0 for Female) (current: %s): ",
               students[found].gender ? "Male" : "Female");
        int gender_input;
        if (scanf("%d", &gender_input) == 1 && (gender_input == 0 || gender_input == 1)) {
            students[found].gender = gender_input;
            break;
        }
        printf("\n\t\tError: Gender must be 1 (Male) or 0 (Female)\n");
        getchar();
    }
    getchar();
    while (1) {
        printf("\tEmail (current: %s): ", students[found].email);
        char temp_email[20];
        fgets(temp_email, sizeof(temp_email), stdin);
        temp_email[strcspn(temp_email, "\n")] = '\0';
        if (strlen(temp_email) > 0 && strlen(temp_email) <= 14) {
            strcat(temp_email, "@gmail.com");
            strcpy(students[found].email, temp_email);
            break;
        } else {
            printf("\n\t\tError: Email prefix cannot exceed 14 characters \n");
        }
    }
    while (1) {
        printf("\tPhone (current: %s): ", students[found].phone);
        char temp_phone[20];
        fgets(temp_phone, sizeof(temp_phone), stdin);
        temp_phone[strcspn(temp_phone, "\n")] = '\0';
        if (strlen(temp_phone) > 0 && strlen(temp_phone) <= 19 && strspn(temp_phone, "0123456789") == strlen(temp_phone)) {
            strcpy(students[found].phone, temp_phone);
            break;
        } else {
            printf("\tError: Phone number must be numeric and cannot exceed 19 digits ^ ^\n");
        }
    }
    while (1) {
        printf("\tNumber of courses (current: %d): ", students[found].number_course);
        int courses;
        if (scanf("%d", &courses) == 1 && courses >= 0) {
            students[found].number_course = courses;
            break;
        }
        printf("\n\t\tError: Number of courses must be a non-negative integer\n");
        getchar();
    }
    printf("\nStudent information updated successfully.\n");
}
void searchStudent() {
    if (n <= 0) {
        printf("\n\tNo student data to search ^ ^\n");
        return;
    }
    char search[50];
    while (1) {
        printf("\tEnter the name or part of the name to search (1-49 characters): ");
        getchar();
		fgets(search, sizeof(search), stdin);
        search[strcspn(search, "\n")] = '\0';
        if (strlen(search) == 0) {
            printf("\n\t\tError: Search string cannot be empty ^ ^\n");
        } else if (strlen(search) > 49) {
            printf("\n\t\tError: Search string is too long (max 49 characters)^ ^\n");
        } else {
            break;
        }
    }
    int found = 0;
    printf("\nSearching for students with name containing ...\n");
    int i;
	for (i = 0; i < n; i++) {
        if (strstr(students[i].name, search) != NULL) {
            if (found == 0) {
                printf("\n\tStudent information found:\n");
                col_s();
		    }
            infor_s(students,i);
            found++;
        }
    }
    if (found == 0) {
        printf("No students found matching \"%s\".\n", search);
    } else {
      row_s();
	}
}
void deletedStudent() {
    if (n <= 0) {
        printf("\n\tNo student data ^ ^\n");
        return;
    }
    printf("\nInput the ID of the student to delete: ");
    char id[20];
    getchar();
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int index = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].student_id, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nStudent with ID: %s not found.\n", id);
        return;
    }
    printf("\nStudent found with ID: %s\n", id);
    col_s();
    infor_s(students, index);
    row_s();
    printf("\nAre you sure you want to delete this student? (YES/NO): ");
    char confirm[10];
    scanf("%s", confirm);
    if (strcmp(confirm, "YES") == 0) {
    	int i;
        for (i = index; i < n - 1; i++) {
            students[i] = students[i + 1];
        }
        n--;
        printf("Student deleted successfully ^ ^\n");
    } else if (strcmp(confirm, "NO") == 0) {
        printf("Deletion canceled.\n");
    } else {
        printf("Invalid input. Deletion canceled.\n");
    }
}
//0giam1tang
void sort_Student_i_or_d() {
    if (n <= 0) {
        printf("\n\tNo student data to sort ^ ^\n");
        return;
    }
    char choice;
    int check = 0;
    do {
        printf("\n   Choose the order in which the student list sorted name is:\n");
        printf("\n\t\t[1]. Increase\n");
        printf("\t\t[2]. Decrease\n");
        printf("\n\tYour choice: ");
        while (getchar() != '\n');
        scanf("%c", &choice);
    } while (choice != '1' && choice != '2');
    check = (choice == '1' ? 1 : 0);
    int i;
    for (i = 0; i < n - 1; i++) {
    	int j;
        for (j = i + 1; j < n; j++) {
            if (check ? strcmp(students[i].name, students[j].name) > 0 :
                        strcmp(students[i].name, students[j].name) < 0) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\nThe list of students after sorted by name is:\n");
    col_s();
    int k;
    for (k = 0; k < n; k++){
	infor_s(students, k);
    }
    row_s();
}
//In ket thuc chuong trinh
void addTeacher(struct Teacher teachers[], int *t) {
    printf("\n\t\tADD A NEW TEACHER\n");
    if (*t >= 50) {
        printf("\n\tError : Max (50 teachers) ^ ^\n");
        return;
    }
    struct Teacher new_teacher;
    while (1) {
        int id = 0;
        printf("\n\tInput ID : ");
        fflush(stdin);
        fgets(new_teacher.teacher_id, sizeof(new_teacher.teacher_id), stdin);
        new_teacher.teacher_id[strcspn(new_teacher.teacher_id, "\n")] = '\0';
        if (strlen(new_teacher.teacher_id) == 0) {
            printSlowly("\n\tError : ID cannot be empty \n", 50);
            printSlowly(" ^ ^ \n", 150);
        } else if (strlen(new_teacher.teacher_id) > 9) {
            printSlowly("\n\tError : ID cannot exceed 9 characters\n", 50);
            printSlowly(" ^ ^ \n", 150);
        } else {
            int i = 0;
            for (i = 0; i < *t; i++) {
                if (strcmp(new_teacher.teacher_id, teachers[i].teacher_id) == 0) {
                    id = 1;
                    printSlowly("\n\tError : ID duplicate\n", 50);
                    printSlowly("\t  Please input a different ID \n", 60);
                    break;
                }
            }
            if (!id) {
                break;
            }
        }
    }
    while (1) {
        printf("\n\tInput teacher name : ");
        fgets(new_teacher.name, sizeof(new_teacher.name), stdin);
        new_teacher.name[strcspn(new_teacher.name, "\n")] = '\0';
        if (strlen(new_teacher.name) == 0) {
            printSlowly("\n\tError : Name cannot be empty", 50);
            printSlowly(" ^ ^\n", 150);
        } else if (strlen(new_teacher.name) > 49) {
            printSlowly("\n\tError : Name cannot exceed 49 characters", 50);
            printSlowly(" ^ ^\n", 150);
        } else {
            break;
        }
    }
    while (1) {
        printf("\n\tInput birthdate (day/month/year) : ");
        if (scanf("%d/%d/%d", &new_teacher.birth.day, &new_teacher.birth.month, &new_teacher.birth.year) != 3) {
            printSlowly("\n\tError : Invalid date format ", 50);
            printSlowly("^ ^\n", 150);
            printSlowly("\n\t   Please again !!\n", 80);
            while (getchar() != '\n');
        } else if (!valid_date(new_teacher.birth.day, new_teacher.birth.month, new_teacher.birth.year)) {
            printSlowly("\n\tError : Invalid date", 50);
            printSlowly(" ^ ^\n", 150);
            printSlowly("\n\t   Please again !!\n", 80);
        } else {
            break;
        }
    }
    while (1) {
        printf("\n\tInput gender (1 for Male, 0 for Female) : ");
        scanf("%d", &new_teacher.gender);
        if (new_teacher.gender != 1 && new_teacher.gender != 0) {
            printSlowly("\n\tError : Gender must be 1 (Male) or 0 (Female)", 50);
            printSlowly(" ^ ^\n", 120);
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    while (1) {
        printf("\n\tInput email (without @gmail.com) : ");
        getchar();
        fgets(new_teacher.email, sizeof(new_teacher.email), stdin);
        new_teacher.email[strcspn(new_teacher.email, "\n")] = '\0';
        if (strlen(new_teacher.email) == 0) {
            printSlowly("\n\tError : Email cannot be empty", 50);
            printSlowly(" ^ ^\n", 120);
        } else if (strlen(new_teacher.email) > 19) {
            printSlowly("\n\tError : Email cannot exceed 19 characters", 50);
            printSlowly(" !!!\n", 120);
        } else {
            strcat(new_teacher.email, "@gmail.com");
            break;
        }
    }
    while (1) {
        printf("\n\tInput phone : ");
        getchar();
        fgets(new_teacher.phone, sizeof(new_teacher.phone), stdin);
        new_teacher.phone[strcspn(new_teacher.phone, "\n")] = '\0';
        if (strlen(new_teacher.phone) == 0) {
            printSlowly("\n\tError : Phone cannot be empty", 50);
            printSlowly(" ^ ^\n", 120);
        } else if (strlen(new_teacher.phone) > 19) {
            printSlowly("\n\tError : Phone cannot exceed 19 characters", 50);
            printSlowly(" ^ ^\n", 120);
        } else if (strspn(new_teacher.phone, "0123456789") != strlen(new_teacher.phone)) {
            printSlowly("\n\tError : Phone number must contain only digits", 50);
            printSlowly(" ^ ^\n", 120);
        } else {
            break;
        }
    }
    while (1) {
        printf("\n\tInput number of classroom number : ");
        fflush(stdin);
        //scanf("%d", &new_teacher.class_number);
        if (scanf("%d", &new_teacher.class_number) != 1 || new_teacher.class_number < 0) {
            printSlowly("\n\t\tError : Number of classroom number must be a positive integer", 50);
            printSlowly(" ^ ^\n", 120);
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    teachers[*t] = new_teacher;
    (*t)++;
    printf("\n\tTeacher added successfully ^ ^\n");
    printf("\n\tNew Teacher Information:\n");
    printf("\n");
    col_t();
    infor_t(teachers, *t - 1);
    row_t();
}
void editTeacher(){
	if(t <= 0){
		printf("\n\tNo teacher data to edit ^ ^\n");
		return;
	}
	char teacher_id[20];
	printf("\n\tInput the ID of the teacher to edit : ");
	scanf("%s",teacher_id);
	getchar();
	int found = -1;
	int i;
	for(i = 0;i < t; i++){
		if(strcmp(teachers[i].teacher_id,teacher_id)==0){
			found = i;
			break;
		}
	}
	if(found == -1){
		printf("\n\t\tTeacher with ID %s not found.\n",teacher_id);
		return;
	}
	printf("\n\t\tEditing information for teacher ID : %s\n",teacher_id);
	while(1){
		printf("\tInput teacher name (current : %s) : ",teachers[found].name);
		char temp_name[50];
		fgets(temp_name,sizeof(temp_name),stdin);
		temp_name[strcspn(temp_name,"\n")]='\0';
		if(strlen(temp_name)>0 && strlen(temp_name)<=49){
			strcpy(teachers[found].name,temp_name);
			break;//////////////
		}else{
			printf("\t\tError : Name cannot exceed 49 characters.\n");
		}
	}
	while(1){
		printf("\tInput birthday (day/month/year) (current : %02d/%02d/%04d) : ",teachers[found].birth.day,teachers[found].birth.month,teachers[found].birth.year);
		int day,month,year;
		if(scanf("%d/%d/%d",&day,&month,&year)==3 && day>=1 && day<=31 && month>=1 && month<=12 && year>=1900 && year<=2050){
			teachers[found].birth.day = day;
			teachers[found].birth.month = month;
			teachers[found].birth.year = year;
			break;
		}
		printf("\t\tError : Invalid date\n");
		getchar();
	}
	while(1){
		printf("\tInput gender (1 for Male or 0 for Female) (current : %s) : ",teachers[found].gender);
		int gender_input;
		scanf("%d",&gender_input);
		if(gender_input==0 || gender_input==1){
			teachers[found].gender = gender_input;
			break;
		}
		printf("\t\tError : Gender must be 1 (Male) or 0 (Female)");
	}
	while(1){
		printf("\n\tInput email (without @gmail.com) (current : %s) : ",teachers[found].email);
		getchar();
		char temp_email[20];
		fgets(temp_email,sizeof(temp_email),stdin);
		temp_email[strcspn(temp_email,"\n")]='\0';
		if(strlen(temp_email)>0 && strlen(temp_email)<=19){
			strcat(temp_email,"@gmail.com");
			strcpy(teachers[found].email,temp_email);
			break;
		}else{
			printf("\n\tError : Email prefix cannot exceed 19 characters ^ ^\n");
		}
	}
	while(1){
		printf("\tInput phone (current : %s) : ",teachers[found].phone);
		char temp_phone[20];
		fgets(temp_phone,sizeof(temp_phone),stdin);
		temp_phone[strcspn(temp_phone,"\n")]='\0';
		if(strlen(temp_phone)>0 && strlen(temp_phone)<=19 && strspn(temp_phone, "0123456789") == strlen(temp_phone)){
			strcpy(teachers[found].phone,temp_phone);
			break;
		}else{
			printf("\n\tError : Phone number must be numeric and cannot exceed 19 digits ^ ^\n");
		}
	}
    while(1){
		printf("\tInput number of classroom number (current : %d) : ",teachers[found].class_number);
		int course;
		//fflush(stdin);
		getchar();
		scanf("%d",&course);
		if(course>=0){
			teachers[found].class_number = course;
			break;
		}
		printf("\n\t\tError : Number of courses must be a non-negative integer ^ ^\n");
		//fflush(stdout);
		getchar();
	}
	printSlowly("\n\t\tTeacher information updated successfully",70);
	printSlowly(" ...\n",120);
}
void deletedTeacher(){
	if(t <= 0){
		printf("\n\tNo teacher data ^ ^\n");
		return;
	}
	printf("\n\tInput the ID of the teacher to delete : ");
	char teacher_id[20];
	getchar();
	fgets(teacher_id,sizeof(teacher_id),stdin);
	teacher_id[strcspn(teacher_id,"\n")]='\0';
	int found = -1;
	int i;
	for(i = 0;i < t; i++){
		if(strcmp(teachers[i].teacher_id,teacher_id)==0){
			found = i;
			break;
		}
	}
	if(found == -1){
		printf("\n\t\tTeacher with ID %s not found.\n",teacher_id);
		return;
	}
	printf("\n\t\tTeacher information found with ID %s\n",teacher_id);
	col_t();
	infor_t(teachers,found);
	row_t();
	printf("\n\tAre you sure you want to delete this teacher? (YES/NO) : ");
	char confirm[10];
	scanf("%s",confirm);
	if(strcmp(confirm,"YES")==0){
			int i;
		for(i = found; i < t-1; i++){
			teachers[i] = teachers[i+1];
		}
		t--;
		printf("\n\t\tTeacher deleted successfully ^ ^\n");
	}else if(strcmp(confirm,"NO")==0){
		printf("\n\t\tDeletion canceled.\n");
	}else{
		printSlowly("\n\t\tInvalid input. Deletion canceled ...\n",70);
	}
}
void searchTeacher(){
	if (n <= 0) {
        printf("\n\tNo teacher data to search ^ ^\n");
        return;
    }
	char search[50];
	while (1){
		printf("\n\tInput the ID of the teacher to search : ");
		getchar();
		fgets(search, sizeof(search), stdin);
        search[strcspn(search, "\n")] = '\0';
		if(strlen(search)==0){
			printf("\n\t\tError : ID cannot be empty ^ ^\n");
		}else if(strlen(search)>9){
			printf("\n\t\tError : ID cannot exceed 9 characters ^ ^\n");
		}else{
			break;
		}
	}
	int check = 0;
	int i;
	for(i = 0;i < t; i++){
		if(strstr(teachers[i].name,search) != NULL){
			if (check == 0) {
                printf("\n\tStudent information found:\n");
                col_t();
		    }
            infor_t(teachers,i);
            check++;
		}
	}
	if(check == 0){
		printf("\n\t\tTeacher with ID %s not found.\n",search);
		return;
	}else{
		row_t();
	}
}
void sort_Teacher_i_or_d(){
	if(t <= 0){
		printf("\n\t\tNo teacher data to sort ^ ^\n");
		return;
	}
	char choice;
	int check = 0;
	do{
		printf("\n\tChoose the order in which the teacher list is sorted : \n");
		printf("\n\t\t[1]. Increase\n");
		printf("\t\t[2]. Decrease\n");
		printf("\n\tYour choice : ");
		while(getchar()!='\n');
		scanf("%c",&choice);
	}while(choice != '1' && choice != '2');
	check = (choice == '1' ? 1 : 0);
	int i;
	for(i = 0;i < t-1; i++){
			int j;
		for(j = i+1; j < t; j++){
			if(check ? strcmp(teachers[i].name,teachers[j].name) > 0 :
			           strcmp(teachers[i].name,teachers[j].name) < 0){
				struct Teacher temp = teachers[i];
				teachers[i] = teachers[j];
				teachers[j] = temp;
			}
		}
	}
	printf("\n\tThe list of teachers after sorted by name is : \n");
	printf("\n");
	col_t();
	int k;
	for(k = 0;k < t; k++){
		infor_t(teachers,k);
	}
	row_t();
}
void addClass(struct Classroom classrooms[], int *c){
	printf("\n\t\tADD A NEW CLASSROOM\n");
	if(*c >=50){
		printf("\n\t\tError : Max (50 classroom) ^ ^\n");
		return;
	}
	struct Classroom new_classroom;
	while(1){
		int id=0;
		printf("\n\tInput ID : ");
		getchar();
		fgets(new_classroom.class_id,sizeof(new_classroom.class_id),stdin);
		new_classroom.class_id[strcspn(new_classroom.class_id,"\n")]='\0';
		if(strlen(new_classroom.class_id)==0){
		   printSlowly("\n\t\tError : ID cannot be empty",50);
		   printSlowly(" ^ ^ \n",150);
		}else if(strlen(new_classroom.class_id)>9){
			printSlowly("\n\t\tErorr : ID cannot exceed 9 characters\n",50);
			printSlowly(" ^ ^ \n",150);
		}else{
			int i=0;
			for(i=0;i<*c;i++){
				if(strcmp(new_classroom.class_id,classrooms[i].class_id)==0){
					id=1;
					printSlowly("\n\t\tError : ID duplicate\n",50);
					printSlowly("\t\t  Please input a different ID \n",60);
					break;
				}
			}
			if(!id){
				break;
			}
		}
	}
	while(1){
		printf("\n\tInput classroom name : ");
		fgets(new_classroom.class_name,sizeof(new_classroom.class_name),stdin);
		new_classroom.class_name[strcspn(new_classroom.class_name,"\n")]='\0';
		if(strlen(new_classroom.class_name)==0){
			printSlowly("\n\t\tError : Name cannot be empty",50);
			printSlowly(" ^ ^\n",150);
		}else if(strlen(new_classroom.class_name)>49){
			printSlowly("\n\t\tError : Name cannot exceed 49 characters",50);
			printSlowly(" ^ ^\n",150);
		}else{
			break;
		}
	}
	while(1){
		printf("\n\tInput teacher ID : ");
		fgets(new_classroom.teacher_id,sizeof(new_classroom.teacher_id),stdin);
		new_classroom.teacher_id[strcspn(new_classroom.teacher_id,"\n")]='\0';
		if(strlen(new_classroom.teacher_id)==0){
			printSlowly("\n\tError : Teacher ID cannot be empty",50);
			printSlowly(" ^ ^\n",150);
		}else if(strlen(new_classroom.teacher_id)>9){
			printSlowly("\n\tError : Teacher ID cannot exceed 9 characters",50);
			printSlowly(" ^ ^\n",150);
		}else{
			break;
		}
	}
	while(1){
		printf("\n\tInput teacher name : ");
		fgets(new_classroom.teacher_name,sizeof(new_classroom.teacher_name),stdin);
		new_classroom.teacher_name[strcspn(new_classroom.teacher_name,"\n")]='\0';
		if(strlen(new_classroom.teacher_name)==0){
			printSlowly("\n\tError : Teacher name cannot be empty",50);
			printSlowly(" ^ ^\n",150);
		}else if(strlen(new_classroom.teacher_name)>49){
			printSlowly("\n\tError : Teacher name cannot exceed 49 characters",50);
			printSlowly(" ^ ^\n",150);
		}else{
			break;
		}
	}
	while(1){
		printf("\n\tInput number of students : ");
		if(scanf("%d",&new_classroom.student_number) < 0){
			printSlowly("\n\tError : Number of students must be a positive integer",50);
			printSlowly(" ^ ^\n",150);
			while (getchar() != '\n');
		}else if(new_classroom.student_number>50){
			printSlowly("\n\tError : Number of students cannot exceed 50",50);
			printSlowly(" ^ ^\n",150);
		}else{
			break;
		}
	}
	classrooms[*c] = new_classroom;
	(*c)++;
	printf("\n\tClassroom added successfully ^ ^\n");
	printf("\n\tNew Classroom Information:\n");
	col_c();
	infor_c(classrooms, *c - 1);
	row_c();
}
void editClass(){
	if(c <= 0){
		printf("\n\tNo classroom data to edit ^ ^\n");
		return;
	}
	char classroom_id[20];
	printf("\n\tInput the ID of the classroom to edit : ");
	scanf("%s",classroom_id);
	getchar();
	int found = -1;
	int i;
	for(i = 0;i < c; i++){
		if(strcmp(classrooms[i].class_id,classroom_id)==0){
			found = i;
			break;
		}
	}
	if(found == -1){
		printf("\n\t\tClassroom with ID %s not found.\n",classroom_id);
		return;
	}
	printf("\n\tEditing information for classroom ID : %s\n",classroom_id);
	while(1){
		printf("\n\tInput classroom name (current : %s) : ",classrooms[found].class_name);
		char temp_name[50];
		fgets(temp_name,sizeof(temp_name),stdin);
		temp_name[strcspn(temp_name,"\n")]='\0';
		if(strlen(temp_name)>0 && strlen(temp_name)<=49){
			strcpy(classrooms[found].class_name,temp_name);
			break;
		}else{
			printf("\n\t\tError : Name cannot exceed 49 characters\n");
		}
	}
	while(1){
		printf("\n\tInput teacher ID (current : %s) : ",classrooms[found].teacher_id);
		char temp_teacher_id[10];
		fgets(temp_teacher_id,sizeof(temp_teacher_id),stdin);
		temp_teacher_id[strcspn(temp_teacher_id,"\n")]='\0';
		if(strlen(temp_teacher_id)>0 && strlen(temp_teacher_id)<=9){
			strcpy(classrooms[found].teacher_id,temp_teacher_id);
			break;
		}else{
			printf("\n\t\tError : Teacher ID cannot exceed 9 characters\n");
		}
	}
	while(1){
		printf("\n\tInput teacher name (current : %s) : ",classrooms[found].teacher_name);
		char temp_teacher_name[50];
		fgets(temp_teacher_name,sizeof(temp_teacher_name),stdin);
		temp_teacher_name[strcspn(temp_teacher_name,"\n")]='\0';
		if(strlen(temp_teacher_name)>0 && strlen(temp_teacher_name)<=49){
			strcpy(classrooms[found].teacher_name,temp_teacher_name);
			break;
		}else{
			printSlowly("\n\t\tError : Teacher name cannot exceed 49 characters ",50);
			printSlowly("^ ^\n",120);
		}
	}
	while(1){
		printf("\n\tInput number of students (current : %d) : ",classrooms[found].student_number);
		int students;
		if(scanf("%d",&students)==1 && students>=0){
			classrooms[found].student_number = students;
			break;
		}else{
			printSlowly("\n\t\tError : Number of students must be a non-negative integer",50);
			printSlowly(" ^ ^\n",120);
			fflush(stdin);
		}
	}
	printf("\n\tClassroom information updated successfully.\n");
}
void deletedClass(){
	if(c <= 0){
		printf("\n\tNo classroom data ^ ^\n");
		return;
	}
	printf("\nInput the ID of the classroom to delete : ");
	char id[20];
	getchar();
	fgets(id,sizeof(id),stdin);
	id[strcspn(id,"\n")]='\0';
	int index = -1;
	int i;
	for(i = 0; i < c; i++){
		if(strcmp(classrooms[i].class_id,id)==0){
			index = i;
			break;
		}
	}
	if(index == -1){
		printf("\nClassroom with ID: %s not found.\n",id);
		return;
	}
	printf("\nClassroom found with ID: %s\n",id);
	col_c();
	infor_c(classrooms, index);
	row_c();
	printf("\nAre you sure you want to delete this classroom? (YES/NO): ");
	char confirm[10];
	scanf("%s", confirm);
	if(strcmp(confirm, "YES") == 0){
		int i;
		for(i = index; i < c - 1; i++){
			classrooms[i] = classrooms[i + 1];
		}
		c--;
		printf("Classroom deleted successfully ^ ^\n");
	}else if(strcmp(confirm, "NO") == 0){
		printf("Deletion canceled.\n");
	}else{
		printf("Invalid input. Deletion canceled.\n");
	}
}
void sort_Class_i_or_d(){
	if(c <= 0){
		printf("\n\tNo classroom data to sort ^ ^\n");
		return;
	}
	char choice;
	int check = 0;
	do{
		printf("\n   Choose the order in which the classroom list is sorted by name:\n");
		printf("\n\t\t[1]. Increase\n");
		printf("\t\t[2]. Decrease\n");
		printf("\n\tYour choice: ");
		while(getchar() != '\n');
		scanf("%c", &choice);
	}while(choice != '1' && choice != '2');
	check = (choice == '1' ? 1 : 0);
	int i;
	for(i = 0; i < c - 1; i++){
		int j;
		for(j = i + 1; j < c; j++){
			if(check ? strcmp(classrooms[i].class_name, classrooms[j].class_name) > 0 :
						strcmp(classrooms[i].class_name, classrooms[j].class_name) < 0){
				struct Classroom temp = classrooms[i];
				classrooms[i] = classrooms[j];
				classrooms[j] = temp;
			}
		}
	}
	printf("\n\tThe list of classrooms after sorting is:\n");
	printf("\n");
	col_c();
	int k;
	for(k = 0; k < c; k++){
		infor_c(classrooms, k);
	}
	row_c();
}
void printfinish(){
	printf("\n\t\t========== Thank You ==========");
	printf("\n\t\t ======= See You Soon ========");
}
void back_or_exit(){
	char choice;
    while(1){
	printf("\n\t\tGo back (b) or Exit (0) ? : ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == '0'){
		printSlowly("\n\tExiting program",40);
		printSlowly("...\n",160);
		printfinish();
		exit(0);
	}else if(choice == 'b'){
		return;
	}else{
		printSlowly("\n\t\t\tInvalid choice",100);
		printSlowly(" !!!\n",180);
	}
    }
}
int main(){
	int menu;
    menuStart(&menu);
    switch (menu){
	    case 1:
            while (1) {
                int choice_s;
                system("cls");
                studentMenu();
                scanf("%d", &choice_s);
                switch (choice_s) {
                    case 1:
                    	system("cls");
                        read_file_s(students,&n);
                        show_student_list(students,n);
						back_or_exit();
                        break;
                    case 2:
                    	system("cls");
                    	read_file_s(students,&n);
                        addStudent(students, &n);
                        save_file_s(students,&n);
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                    	read_file_s(students,&n);
                        editStudent();
                        save_file_s(students,&n);
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                    	read_file_s(students,&n);
                    	searchStudent();
                    	back_or_exit();
                    	break;
                    case 5:
                    	system("cls");
                    	read_file_s(students,&n);
                    	sort_Student_i_or_d();
                    	back_or_exit();
                    	break;
					case 6:
						system("cls");
						read_file_s(students,&n);
						deletedStudent();
					    save_file_s(students,&n);
						back_or_exit();
						break;
					case 7:
                        printSlowly("\nExisting student menu",50);
                        printSlowly("...\n",150);
						printfinish();
                        return 0;
                    default:
                        printf("\tInvalid choice. Please try again.\n");
                        break;
                }
            }
            break;
        case 2:
            while(1){
            	int choice_t;
            	system("cls");
            	teacherMenu();
            	scanf("%d", &choice_t);
                switch (choice_t) {
                    case 1:
                    	system("cls");
                    	//read_file_t(teachers,&t);
                        show_teacher_list(teachers,&t);
						back_or_exit();
                        break;
                    case 2:
                    	system("cls");
                      //read_file_t(teachers,&t);
                        addTeacher(teachers, &t);
                      //save_file_t(teachers,&t);
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                      //read_file_t(teachers,&t);
                        editTeacher();
                      //save_file_t(teachers,&t);
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                      //read_file_t(teachers,&t);
                    	searchTeacher();
                    	back_or_exit();
                    	break;
                    case 5:
                    	system("cls");
                      //read_file_t(teachers,&t);
                    	sort_Teacher_i_or_d();
                    	back_or_exit();
                    	break;
					case 6:
						system("cls");
				      //read_file_t(teachers,&t);
						deletedTeacher();
					  //save_file_t(teachers,&t);
						back_or_exit();
						break;
					case 7:
                        printSlowly("\nExisting teacher menu",50);
                        printSlowly("...\n",150);
				        printfinish();
                        return 0;
                    default:
                        printf("\n\tInvalid choice. Please try again.\n");
                        break;
                }
            }
            break;
        case 3:
        	while(1){
            	int choice_c;
            	system("cls");
            	classMenu();
            	scanf("%d", &choice_c);
                switch (choice_c) {
                    case 1:
                    	system("cls");
                        read_file_c(classrooms,&c);
                        show_class_list(classrooms,c);
						back_or_exit();
                        break;
                    case 2:
                    	system("cls");
                    	read_file_c(classrooms,&c);
                        addClass(classrooms, &c);
                        save_file_c(classrooms,&c);
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                    	read_file_c(classrooms,&c);
                        editClass();
                        save_file_c(classrooms,&c);
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                    	read_file_c(classrooms,&c);
                    	sort_Class_i_or_d();
                    	back_or_exit();
                    	break;
					case 5:
						system("cls");
						read_file_c(classrooms,&c);
						deletedClass();
					    save_file_c(classrooms,&c);
						back_or_exit();
						break;
					case 6: 
					    system("cls");
					    printSlowly("Under development ",70);
					    printSlowly("^ ^",120);
					case 7:
                        printSlowly("\nExisting classroom menu",50);
                        printSlowly("...",150);
						printfinish();
                        return 0;
                    default:
                        printf("\n\tInvalid choice. Please try again.\n");
                        break;
                }
            }
        case 4:
        	printf("\n\tAdmin role is under development.\n");
        	break;
        case 5:
            printSlowly("\n\tExiting program",50);
            printSlowly("...\n",150);
            printfinish();
            return 0;
        default:
            printSlowly("\n\tInvalid choice. Exiting",50);
            printSlowly("...\n",150);
            back_or_exit();
            break;
    }
}





