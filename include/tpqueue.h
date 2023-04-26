// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  typedef struct node {
    T value;
    struct node* next;
  } Node;
  
	Node* front;
 public:
  
  TPQueue() : front(NULL) {}
  ~TPQueue() {
    while (front != NULL)
      pop();
  }
  void push(const T& value) {
    Node* temp, *curr, *pre = NULL;
    temp = new Node;
    temp->value = value;
    if (front == NULL || value.prior > front->value.prior) {
      temp->next = front;
      front = temp;
    } else {
      curr = front;
      while (curr && value.prior <= curr->value.prior) {
        pre = curr;
        curr = curr->next;
      }
      temp->next = pre->next;
      pre->next = temp;
    }
  }
  T pop() {
    if (front == NULL) {
      throw std::string("Empty");
    } else {
      Node* temp;
      temp = front;
      T value = temp->value;
      front = temp->next;
      free(temp);
      return value;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
