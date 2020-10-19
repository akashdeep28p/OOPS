
#include <iostream>
using namespace std;

class CMPT135_String
{
private:
	char *buffer;	//This will be the dynamic array to hold the characters
public:
	//static member function to compute the length of null terminated char arrays
	static int cstrlen(const char *cStr); 

	//Constructors
	CMPT135_String();
	CMPT135_String(const char &c);
	CMPT135_String(const char *cStr); //*cStr is a null terminated char array
	CMPT135_String(const CMPT135_String &s);

	//Destructor
	~CMPT135_String();

	//Assignment operators
	CMPT135_String& operator = (const CMPT135_String &s);
	CMPT135_String& operator = (const char &c);
	CMPT135_String& operator = (const char *cStr); //*cStr is a null terminated char array

	//Getter member functions
	int getLength() const ;
	char& operator[](const int &index) const ;

	//Setter member functions
	void append(const char &c);
	void append(const CMPT135_String &s);
	void append(const char *cStr); //*cStr is a null terminated char array

	//Other member functions
	int findCharIndex(const char &c) const;
	int reverseFindCharIndex(const char &c) const;
	int countChar(const char &c) const;
	CMPT135_String getSubString(const int &startIndex, const int &len) const;
	bool isSubString(const CMPT135_String &s) const;
	bool isSubString(const char *cStr) const; //*cStr is a null terminated char array
	void reverse();
	void removeChar(const char &c);
	void replaceChar(const char &c1, const char &c2);

	//Operator member functions
	CMPT135_String operator + (const char &c) const;
	CMPT135_String operator + (const CMPT135_String &s) const;
	CMPT135_String operator + (const char *cStr) const; //*cStr is a null terminated char array
	CMPT135_String& operator += (const char &c);
	CMPT135_String& operator += (const CMPT135_String &s);
	CMPT135_String& operator += (const char *cStr); //*cStr is a null terminated char array
	bool operator == (const CMPT135_String &s) const;
	bool operator == (const char *cStr) const; //*cStr is a null terminated char array
	bool operator != (const CMPT135_String &s) const;
	bool operator != (const char *cStr) const; //*cStr is a null terminated char array
	bool operator < (const CMPT135_String &s) const;
	bool operator < (const char *cStr) const; //*cStr is a null terminated char array
	bool operator > (const CMPT135_String &s) const;
	bool operator > (const char *cStr) const; //*cStr is a null terminated char array
	bool operator <= (const CMPT135_String &s) const;
	bool operator <= (const char *cStr) const; //*cStr is a null terminated char array
	bool operator >= (const CMPT135_String &s) const;
	bool operator >= (const char *cStr) const; //*cStr is a null terminated char array

	//Friend Functions (for operators)
	friend CMPT135_String operator + (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend CMPT135_String operator + (const char &c, const CMPT135_String &s);
	friend bool operator == (const char *cStr, const CMPT135_String &s); //*cStr a null terminated char array
	friend bool operator != (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator < (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator > (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator <= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator >= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend ostream& operator << (ostream &outputStream, const CMPT135_String &s);
	friend istream& operator >> (istream &inputStream, CMPT135_String &s);
};

int CMPT135_String::cstrlen(const char *cStr){

	if(cStr == nullptr)return 0;

	int i  =0;
	int cnt =0 ;
	while(cStr[i] != '\0'){
		i++;
		cnt++;
	}

	return cnt;
}

CMPT135_String::CMPT135_String(){
	buffer = new char[1000];
	buffer[0] = '\0';
}

CMPT135_String::CMPT135_String(const char *cStr ){

	buffer = new char[1000];
	int i =0 ;
	while(cStr[i] != '\0'){
		buffer[i] = cStr[i];
		i++;
	}
	buffer[i] = '\0';
}

CMPT135_String::CMPT135_String(const char &c ){

	buffer = new char[1000];
	int i =0;

	buffer[i] = c;
	i++;
	buffer[i] = '\0';

}
CMPT135_String::~CMPT135_String(){
	delete buffer;
	buffer = nullptr;
}

// copy constructor
CMPT135_String::CMPT135_String(const CMPT135_String &s){

	buffer = new char[1000];
	int i = 0;
	while(s.buffer[i] != '\0'){
		buffer[i] = s.buffer[i];
		i++;
	}
	buffer[i] = '\0';
}


// assignment operator
CMPT135_String& CMPT135_String::operator=(const CMPT135_String& s){
	buffer = new char[1000];

	int i  =0;
	while(s.buffer[i] != '\0'){
		buffer[i] = s.buffer[i];
		i++;
	}
	buffer[i] = '\0';

	return *this;
}

CMPT135_String& CMPT135_String::operator=(const char& c){
	buffer = new char[1000];

	int i  =0;
	buffer[i] = c;
	i++;
	buffer[i]='\0';

	return *this;
}


CMPT135_String& CMPT135_String::operator=(const char* cStr){
	buffer = new char[1000];

	int i =0;
	while(cStr[i] != '\0'){
		buffer[i] = cStr[i];
		i++;
	}

	buffer[i] = '\0';

	return *this;
}


// Indexing operator
char& CMPT135_String::operator[](const int &index) const{

	int i = 0;
	while(i!= index){
		i++;
	}

	return buffer[i];

}

// append function
void CMPT135_String::append(const char& c){

	int i = 0;
	while(buffer[i] != '\0'){
		i++;
	}
	buffer[i] = c;
	i++;
	buffer[i] = '\0';

}

void CMPT135_String::append(const char* cStr){

	int i = 0;
	while(buffer[i] != '\0'){
		i++;
	}

	int j = 0;
	while(cStr[j] != '\0'){
		buffer[i] = cStr[j];
		i++;
		j++;
	}

	buffer[i] = '\0';
}

void CMPT135_String::append(const CMPT135_String& s){

	int i = 0;
	while(buffer[i] != '\0'){
		i++;
	}

	int j = 0;
	while(s.buffer[j] != '\0'){
		buffer[i] = s.buffer[j];
		i++;
		j++;
	}

	buffer[i] = '\0';
}

// get length 
int CMPT135_String::getLength() const{
	if(buffer == nullptr)return 0;

	int i = 0 ;
	int cnt =0 ;
	while(buffer[i] != '\0'){
		i++;
		cnt++;
	}
	return cnt;
}


int CMPT135_String::findCharIndex(const char &c) const{
	int idx = 0;
	while(buffer[idx] != '\0'){
		if(buffer[idx] == c)return idx;

		idx++;
	}
	return -1;
}


int CMPT135_String::reverseFindCharIndex(const char &c) const{
	int idx = 0;
	while(buffer[idx] != '\0')idx++;

	while(idx>=0){
		if(buffer[idx] == c)return idx;

		idx--;
	}

	return -1;
}

// get substring
CMPT135_String CMPT135_String::getSubString(const int &startIndex, const int &len) const{
	CMPT135_String str;
	int i = 0;

	int j = startIndex;
	int cnt = 0;
	while(cnt< len && buffer[j] != '\0'){
		str.buffer[i] = buffer[j];
		i++;
		j++;
		cnt++;
	}

	str.buffer[i] = '\0';
	return str;
}



	
// is substring
bool CMPT135_String::isSubString(const CMPT135_String &s) const{
	int m = this->getLength();
	int n = s.getLength();

	for(int i =0 ; i<= n-m ; i++){
		int j ;
		for(j =0 ; j<m ; j++)
			if(s[i+j] != buffer[j])
				break;

			if(j==m)
				return true;
	}

	return false;
}

bool CMPT135_String::isSubString(const char* cStr) const{
	int m = this->getLength();
	int n = CMPT135_String::cstrlen(cStr);

	for(int i =0 ; i<= n-m ; i++){
		int j ;
		for(j =0 ; j<m ; j++)
			if(cStr[i+j] != buffer[j])
				break;

			if(j==m)
				return true;
	}

	return false;
}


// reverse
void CMPT135_String::reverse(){
	int i =0 , j =0;
	while(buffer[j] != '\0')j++;

	j--;
	while(i<j){
		swap(buffer[i] , buffer[j]);
		i++;
		j--;
	}
}

//count char
int CMPT135_String::countChar(const char &c) const{

	int cnt = 0;
	int i =0 ;
	while(buffer[i] != '\0'){
		if(buffer[i] == c)cnt++;

		i++;
	}

	return cnt;
}



void CMPT135_String::removeChar(const char &c){

	char ch[1000];
	int i =0;
	int j =0;
	while(buffer[i] != '\0'){
		if(buffer[i] != c){
			ch[j] = buffer[i];
			j++;
		}

		i++;
	}

	ch[j] = '\0';

	j = 0;
	while(ch[j] != '\0'){
		buffer[j] = ch[j];
		j++;
	}

	buffer[j] = '\0';
}


// replace char
void CMPT135_String::replaceChar(const char &c1, const char &c2){
	int i = 0;
	while(buffer[i] != '\0'){
		if(buffer[i] == c1)buffer[i] = c2;
		i++; 
	}
}

CMPT135_String CMPT135_String::operator + (const CMPT135_String &s) const{
	CMPT135_String str ;
	int i =0 ;
	while(buffer[i] != '\0'){
		str.buffer[i] = buffer[i];
		i++;
	}

	int j  =0 ;
	while(s.buffer[j] != '\0'){
		str.buffer[i] = buffer[j];
		i++;
		j++;
	}

	str.buffer[i] = '\0';
	return str;
}

CMPT135_String CMPT135_String::operator + (const char *cStr) const{
	CMPT135_String str ;
	int i  =0;
	while(buffer[i] != '\0'){
		str.buffer[i] = buffer[i];
		i++;
 	}

	int j = 0; 	
	while(cStr[j] != '\0'){
		str.buffer[i] = cStr[j];
		i++;
		j++;
	}

	str.buffer[i] = '\0';
	return str;
}

CMPT135_String CMPT135_String::operator + (const char &c) const{
	CMPT135_String str;
	int i = 0;
	while(buffer[i] != '\0'){
		str.buffer[i] = buffer[i];
		i++;
	}
	str.buffer[i] = c;
	i++;
	str.buffer[i] = '\0';

	return str;

}


// += operator
CMPT135_String& CMPT135_String::operator += (const CMPT135_String &s){

	int i = 0;

	while(buffer[i] != '\0'){
		i++;
	}

	int j = 0;
	while(s.buffer[j] != '\0'){
		buffer[i] = s.buffer[j];
		i++;
		j++;
	}

	buffer[i] = '\0';

	return *this;


}

CMPT135_String& CMPT135_String::operator += (const char &c){

	int i  =0;
	while(buffer[i] != '\0')i++;

	buffer[i] = c;
	i++;
	buffer[i] = '\0';
	
	return *this;
}


CMPT135_String& CMPT135_String::operator += (const char *cStr){

	int i = 0 ;
	while(buffer[i] != '\0')i++;

	int j =0;
	while(cStr[j] != '\0'){
		buffer[i] = cStr[j];
		i++;
		j++;
	}

	buffer[i] = '\0';

	return *this;

}






// relationship operators
bool CMPT135_String::operator == (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(buffer[i] != s[i])return false;
	}

	return l1 == l2;
}

bool CMPT135_String::operator == (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return false;
	}

	return l1 == l2;

}
bool CMPT135_String::operator != (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(buffer[i] != s[i])return true;
	}

	return l1 != l2;
}

bool CMPT135_String::operator != (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return true;
	}

	return l1 != l2;
}


bool CMPT135_String::operator < (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != s[i])return buffer[i] < s[i];
	}

	return l1 < l2;
}

bool CMPT135_String::operator < (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return buffer[i] < cStr[i];
	}

	return l1 < l2;

}


bool CMPT135_String::operator > (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != s[i])return buffer[i] > s[i];
	}

	return l1 > l2;

}

bool CMPT135_String::operator > (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return buffer[i] > cStr[i];
	}

	return l1 > l2;
}

bool CMPT135_String::operator <= (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != s[i])return buffer[i] < s[i];
	}

	return l1 <= l2;

}
bool CMPT135_String::operator <= (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return buffer[i] < cStr[i];
	}

	return l1 <= l2;
}

bool CMPT135_String::operator >= (const CMPT135_String &s) const{
	int l1 = this->getLength();
	int l2 = s.getLength();

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != s[i])return buffer[i] > s[i];
	}

	return l1 >= l2;

}

bool CMPT135_String::operator >= (const char *cStr) const{
	int l1 = this->getLength();
	int l2 = CMPT135_String::cstrlen(cStr);

	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(buffer[i] != cStr[i])return buffer[i] > cStr[i];
	}

	return l1 >= l2;

}


//friend relational operators
bool operator == (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(cStr[i] != s[i])return false;
	}

	return l1 == l2;

}
bool operator != (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();

	int lmin = min(l1 ,l2);
	for(int i =0  ; i< lmin ; i++){
		if(cStr[i] != s[i])return true;
	}

	return l1 != l2;
}
bool operator < (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();


	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(cStr[i] != s[i])return cStr[i] < s[i];
	}

	return l1 < l2;

}
bool operator > (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();


	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(cStr[i] != s[i])return cStr[i] > s[i];
	}

	return l1 > l2;

}
bool operator <= (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();


	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(cStr[i] != s[i])return cStr[i] < s[i];
	}

	return l1 <= l2;

}

bool operator >= (const char *cStr, const CMPT135_String &s){
	int l1 = CMPT135_String::cstrlen(cStr);
	int l2 = s.getLength();


	int lmin = min(l1 , l2);

	for(int  i = 0 ; i< lmin ; i++){
		if(cStr[i] != s[i])return cStr[i] > s[i];
	}

	return l1 >= l2;

}


// friend functions
CMPT135_String operator + (const char *cStr, const CMPT135_String &s){
	CMPT135_String str;
	int i = 0;
	while(cStr[i] != '\0'){
		str.buffer[i] = cStr[i];
		i++;
	}

	int j = 0;
	while(s.buffer[j] != '\0'){
		str.buffer[i] = s.buffer[j];
		i++;
		j++;
	}

	str.buffer[i] = '\0';

	return str;
}

CMPT135_String operator + (const char &c, const CMPT135_String &s){
	CMPT135_String str;
	int i =0;
	str.buffer[i] = c;
	i++;
	int j =0;
	while(s.buffer[j] != '\0'){
		str.buffer[i] = s.buffer[j];
		i++;
		j++;
	}

	str.buffer[i] = '\0';
	return str;
}


ostream& operator<<(ostream& out , const CMPT135_String& cStr){
	if(cStr.buffer == nullptr){
		cout<<"";
		return out;
	}

	int i =0;
	while(cStr.buffer[i] != '\0'){
		out<<cStr.buffer[i];
		i++;
	}
	return out;
}

istream& operator>>(istream& in , CMPT135_String& cStr){
	cin.getline(cStr.buffer , 1000);

	return in;
}




int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt","w", stdout);
	// #endif
	
	//Test the cstrlen static member function'
	cout << "The length of \"Yonas\" is " << CMPT135_String::cstrlen("Yonas") << endl;
	cout << "The length of \"\" is " << CMPT135_String::cstrlen("") << endl;
	cout << "The length of nullptr is " << CMPT135_String::cstrlen(nullptr) << endl;

	// //Test default constructor and getLength member functions
	CMPT135_String s1 ; 	
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	// //Test non-default constructor and getLength member functions
	CMPT135_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.getLength() << endl;

	// //Test non-default constructor and getLength member functions
	CMPT135_String s3 = "CMPT 135";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	// //Test copy constructor and getLength member functions
	CMPT135_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;
	
	// //Test destructor and getLength member functions
	s4.~CMPT135_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	// //Test assignment operator and getLength member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	// //Test assignment operator and getLength member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	// //Test assignment operator and getLength member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	// //Test indexing operator
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'a';
	cout << "s4[2] is " << s4[2] << endl;
	s4[3] = 't';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	// //Test append function and getLength member functions
	s1.append(s4);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	// //Test append function and getLength member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	// //Test append function and getLength member functions
	s3.append("201901");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	// //Test findCharIndex function
	char ch = '1';
	int k = s3.findCharIndex(ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.findCharIndex('m');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	// //Test reverseFindCharIndex function
	ch = '1';
	k = s3.reverseFindCharIndex(ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.reverseFindCharIndex('m');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	
	// //Test getSubString function
	s1 = s3.getSubString(10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	
	// //Test isSubString function
	if (s1.isSubString(s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902029010190";
	if (s1.isSubString(s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902019010190";
	if (s1.isSubString(x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;
	
	// //Test reverse function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1.reverse();
	cout << "After reversing it, s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	
	// //Test countChar function
	ch = '1';
	k = s1.countChar(ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	// //Test removeChar function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	s1.removeChar(ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	s3.removeChar(ch);
	cout << "\"" << s3 << "\"" << endl;
	
	// //Test replaceChar function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	s2.replaceChar('1', '5');
	cout << s2 << endl;

	// //Test + operator
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	// //Test += operatror
	s2 = "Test";
	cout << "s1 is \"" << s1 <<"\", s2 is \"" << s2 << "\", and s3 is \"" << s3 << "\"" << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl; 
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	// // //Test relational operators
	s1 = "Test1";
	s2 = "";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	// //Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	// //Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" < s1 is " << ("Test2" < s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" >= s1 is " << ("Test2" >= s1) << endl;

	// //Test input streaming operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;

	// system("pause");
	return 0;
}


// Test Program Output
// ===================
// The length of "Yonas" is 5
// The length of "" is 0
// The length of nullptr is 0
// s1 is "" and its length is 0
// s2 is "Y" and its length is 1
// s3 is "CMPT 135" and its length is 8
// s4 is "CMPT 135" and its length is 8
// s4 is "" and its length is 0
// s4 is "Y" and its length is 1
// s4 is "A" and its length is 1
// s4 is "This is cool" and its length is 12
// s4[2] is i
// s4[2] is a
// s4 is "That is cool" and its length is 12
// s1 is "That is cool" and its length is 12
// s3 is "CMPT 135 " and its length is 9
// s3 is "CMPT 135 201901" and its length is 15
// The first index of '1' in "CMPT 135 201901" is 5
// The first index of 'm' in "CMPT 135 201901" is -1
// The last index of '1' in "CMPT 135 201901" is 14
// The last index of 'm' in "CMPT 135 201901" is -1
// s1 is "019" and its length is 3
// s1 is "01901" and its length is 5
// s1 is "01901" and its length is 5
// "01901" is a substring of "CMPT 135 201901"
// "01901" is not a substring of "01902029010190"
// "01901" is a substring of "01902019010190"
// s1 is "01901" and its length is 5
// After reversing it, s1 is "10910" and its length is 5
// '1' appears 2 times in "10910"
// After removing all the '1' characters from "10910", we get "090"
// After removing all the '1' characters from "11111111111", we get ""
// After replacing 1 by 5 from "01902029010190", we get 05902029050590
// s1 is "090", s3 is "" and s1 + s3 is "090"
// s1 is "090 and s1 + "yonas" is "090yonas
// s1 is "090 and s1 + 'Y' is "090Y
// s1 is "090", s2 is "Test", and s3 is ""
// After s3 = s1 += s2, we get s1 is 090Test, s2 is Test, and s3 is 090Test
// s2 is "Test". After s2 += "FIC", we get "TestFIC"
// s2 is "TestFIC". After s2 += '!', we get "TestFIC!"
// s1 is "Test1", s2 is "" and s1 == s2 is 0
// s1 is "Test1", s2 is "" and s1 != s2 is 1
// s1 is "Test1", s2 is "" and s1 > s2 is 1
// s1 is "Test1", s2 is "" and s1 < s2 is 0
// s1 is "Test1", s2 is "" and s1 >= s2 is 1
// s1 is "Test1", s2 is "" and s1 <= s2 is 0
// "Yonas" + "Test1" is "YonasTest1"
// 'y' + "Test1" is "yTest1"
// s1 is "Test1" and "Test2" == s1 is 0
// s1 is "Test1" and "Test2" != s1 is 1
// s1 is "Test1" and "Test2" < s1 is 0
// s1 is "Test1" and "Test2" > s1 is 1
// s1 is "Test1" and "Test2" <= s1 is 0
// s1 is "Test1" and "Test2" >= s1 is 1
// Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): Was this fun?
// You entered "Was this fun?"
// Press any key to continue . . .