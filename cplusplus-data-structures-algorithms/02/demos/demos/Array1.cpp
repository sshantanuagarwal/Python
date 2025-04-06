// Array1.cpp -- Initial incomplete implementation of the array class.
//               Leaks memory (no destructor implemented yet)

#include <cassert>
#include <iostream>

class IntArray {
 private:
  int* m_ptr{nullptr};
  int  m_size{0};

 public:
  IntArray() = default;

  explicit IntArray(int size) {
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }
 
  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }
};

int main() {
  using std::cout;

  cout << " Creating an empty array.\n";  
  IntArray a{};
  cout << " a.Size() is " << a.Size() << '\n';
  assert(a.IsEmpty());

  cout << " -----------------------------------------\n";

  cout << " Creating an array containing 10 elements.\n";
  IntArray b{10};
  cout << " b.Size() is " << b.Size() << '\n';
  assert(! b.IsEmpty());
}



