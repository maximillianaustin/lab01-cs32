#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  if (head == NULL) {
    head = tail = new Node;
    head->s = new Student(s);
    head->next = NULL;
    if (tail == NULL) {
      tail = head;
    }
  } else {
    tail->next = new Node;
    tail = tail->next;
    tail->s = new Student(s);
    tail->next = NULL;
  }
}

std::string StudentRoll::toString() const {
  std::string temp = std::string("[");
  if (head != NULL) {
    Node *current = head;
    while (current != NULL) {
      temp += current->s->toString();
      if (current->next != NULL) {
        temp += ",";
      }
      current = current->next;
    }
  }
  temp += std::string("]");
  return temp;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if (orig.head == NULL) {
    head = tail = NULL;
    return;
  }
  if (orig.head == orig.tail) {
    head = tail = new Node;
    head->s = new Student(*(orig.head->s));
    head->next = NULL;
    return;
  }
  if (orig.head != orig.tail) {
    head = tail = new Node;
    head->s = new Student(*(orig.head->s));
    head->next = NULL;
    Node *currentOrig = orig.head->next;
    while (currentOrig != NULL) {
      tail->next = new Node;
      tail = tail->next;
      tail->s = new Student(*(currentOrig->s));
      tail->next = NULL;
      currentOrig = currentOrig->next;
    }
  } else {
    head = tail = NULL;
  }
}

StudentRoll::~StudentRoll() {
  if (head != NULL) {
    Node *current = head;
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      delete temp->s;
      delete temp;
    }
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  if (head != NULL) {
    Node *current = head;
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      delete temp->s;
      delete temp;
    }
  }
  head = tail = NULL;
  if (right.head == NULL) {
    head = tail = NULL;
    return (*this);
  }
  if (right.head == right.tail) {
    head = tail = new Node;
    head->s = new Student(*(right.head->s));
    head->next = NULL;
    return (*this);
  }
  if (right.head != right.tail) {
    head = tail = new Node;
    head->s = new Student(*(right.head->s));
    head->next = NULL;
    Node *currentRight = right.head->next;
    while (currentRight != NULL) {
      tail->next = new Node;
      tail = tail->next;
      tail->s = new Student(*(currentRight->s));
      tail->next = NULL;
      currentRight = currentRight->next;
    }
  } else {
    head = tail = NULL;
  }
  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





