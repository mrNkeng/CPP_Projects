// CMSC 341 - Spring 2022 - Project 3
#include "squeue.h"
SQueue::SQueue(prifn_t priFn, HEAPTYPE heapType){
  m_heap = nullptr;
  m_size = 0;
  m_priorFunc = priFn;
  m_heapType = heapType;
}

SQueue::~SQueue(){
 clear();
}

SQueue::SQueue(const SQueue& rhs){
//shallow copy member pointers share memory *they point to the same thing*
//deep copy allocate new memory so the new object doesn't get modified
//rhs represent the old object
m_priorFunc = rhs.m_priorFunc;
m_heap = nullptr;
m_size = rhs.m_size; 

SqHelp(rhs.m_heap, m_heap);
}

void SQueue::SqHelp(const Node* rhs, Node*& lhs){
  if (rhs == nullptr) {
  return;
  }
  lhs = new Node(rhs->m_post);
  SqHelp(rhs->m_left, lhs->m_left);
  SqHelp(rhs->m_right, lhs->m_right);
}

SQueue& SQueue::operator=(const SQueue& rhs){
  if (&rhs != this) { // we get the memory address of rhs to see if its 
       clear();         //the same as the current object which would mean self assigment.
       m_priorFunc = rhs.m_priorFunc;
       m_heap = nullptr;
       m_size = rhs.m_size; 

      SqHelp(rhs.m_heap, m_heap);

    }
    return *this; // The "*this" dereferences the "this" keyword. this function return an SQueue object
}

void SQueue::insertPost(const Post& post) {
  Node* temp = new Node(post);
  m_heap = mergeHelper(m_heap, temp);
  m_size++;
}

Post SQueue::getNextPost() {
  if (m_size == 0){
      throw std::domain_error("the queue is empty");
  }
  Post p_temp = m_heap->getPost();
  Node* temp = mergeHelper(m_heap->m_left, m_heap->m_right);
  delete m_heap;
  m_heap = temp;
  m_size--;
  return p_temp;
}

Node* SQueue::mergeHelper(Node* nodeA, Node* nodeB){ // responsible for merging the nodes
    if(m_heapType == MINHEAP){
      if (nodeA == nullptr) {
        return nodeB;
      }
      if (nodeB == nullptr){
        return nodeA;
      }
      if (m_priorFunc(nodeA->m_post) > m_priorFunc(nodeB->m_post)){
        Node* temp = nodeA;
        nodeA = nodeB; 
        nodeB = temp;// line 73-75 are responsible for swapping the nodes
      }// end if

      Node* temp = nodeA->m_left;
      nodeA->m_left = nodeA->m_right; 
      nodeA->m_right = temp; // if the if statement above isn't met we want to do these
      nodeA->m_left = mergeHelper(nodeA->m_left, nodeB);
      return nodeA;
    }
  
  else {
    if (nodeA == nullptr) {
        return nodeB;
      }
      if (nodeB == nullptr){
        return nodeA;
      }
      if (m_priorFunc(nodeA->m_post) < m_priorFunc(nodeB->m_post)){
        Node* temp = nodeA;
        nodeA = nodeB; 
        nodeB = temp;// line 73-75 are responsible for swapping the nodes
      }// end if

      Node* temp = nodeA->m_left;
      nodeA->m_left = nodeA->m_right; 
      nodeA->m_right = temp; // if the if statement above isn't met we want to do these
      nodeA->m_left = mergeHelper(nodeA->m_left, nodeB);
      return nodeA;
  }
}


void SQueue::mergeWithQueue(SQueue& rhs) {
  // m_priorFunc tells us the priority in the heap
  // we want to check that the priority functions are the same
  if(m_priorFunc != rhs.m_priorFunc){
    throw std::domain_error("The roots have different priorities");
  }
  else if (rhs.m_heap == nullptr){
      return;
  }
  else if (m_heap == nullptr){
    m_heap = rhs.m_heap;
    rhs.m_heap = nullptr;
    return;
  }
  else if (rhs.m_heap == m_heap){ // protection against self assignment
    return;
  }
  m_heap = mergeHelper(m_heap, rhs.m_heap);

  m_size = m_size + rhs.m_size;
  rhs.m_size = 0;
  rhs.m_heap = nullptr; // the purpose of these lines of code is to clear out rhs
}

void SQueue::clearHelp(Node* cleaner) {
if (cleaner != nullptr) {
        clearHelp(cleaner->m_left);
        clearHelp(cleaner->m_right);
        delete cleaner;
        cleaner = nullptr;
    }// end if
}// end clearHelp

void SQueue::clear() {
  clearHelp(m_heap);
  m_heap = nullptr;
}

int SQueue::numPosts() const{
  return m_size;
}

void SQueue::printHelper(Node* printer) const{
    if ( printer != nullptr ) {
    cout << m_priorFunc(printer->m_post) << " " << *printer << endl;
    printHelper(printer->m_left);
    printHelper(printer->m_right);
  }
}

void SQueue::printPostsQueue() const {
  printHelper(m_heap);
}

prifn_t SQueue::getPriorityFn() const {
  return m_priorFunc;
}

void SQueue::setPriorityFn(prifn_t priFn, HEAPTYPE heapType) {
  //remove all data from current queue into new queue
    m_priorFunc = priFn;
    m_heapType = heapType;
    SQueue newQueue(priFn, heapType);
    while (m_heap != nullptr){
      newQueue.insertPost(getNextPost()); // inserting into the new heap
    }
    m_heap = newQueue.m_heap;
    m_size = newQueue.m_size;
    newQueue.m_heap = nullptr;
    //m_priorFunc = priFn;
    //m_heapType = heapType;
    newQueue.m_size = 0;       
}

void SQueue::dump() const
{
  if (m_size == 0) {
    cout << "Empty skew heap.\n" ;
  } else {
    dump(m_heap);
    cout << endl;
  }
}

void SQueue::dump(Node *pos) const {
  if ( pos != nullptr ) {
    cout << "(";
    dump(pos->m_left);
    cout << m_priorFunc(pos->m_post) << ":" << pos->m_post.getPostID();
    dump(pos->m_right);
    cout << ")";
  }
}

ostream& operator<<(ostream& sout, const Post& post) {
  sout << "Post ID: " << post.getPostID() 
        << ", number of likes: " << post.getNumLikes()
        << ", interest level: " << post.getInterestLevel() 
        << ", connection level: " << post.getConnectLevel()
        << ", post time: " << post.getPostTime();
  return sout;
}

ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.getPost();
  return sout;
}