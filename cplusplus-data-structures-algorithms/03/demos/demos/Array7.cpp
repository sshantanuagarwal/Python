// Array7.cpp -- Enable nice idiomatic array printing with operator<< overload

#include <cassert>
#include <ostream>
#include <iostream>

class IndexOutOfBoundsException{};

class IntArray {
 private:
  int* m_ptr{nullptr};
  int  m_size{0};

  bool IsValidIndex(int index) const {
    return (index >= 0) && (index < m_size);
  }

 public:
  IntArray() = default;

  explicit IntArray(int size) {
    assert(size >= 0);
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }
 
  ~IntArray() {
    delete[] m_ptr;
  }

  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  int& operator[](int index) {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }

  int operator[](int index) const {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }
};

std::ostream& operator<<(std::ostream& os, const IntArray& a) {
  os << "[ ";
  for (int i = 0; i < a.Size(); i++) {
    os << a[i] << ' ';
  }
  os << ']';

  return os;
}

int main() {
  using std::cout;

  IntArray a{10};
  for (int i = 0; i < a.Size(); i++) {
    a[i] = (i+1)*10;
  }
    
  cout << " Array elements : " << a << '\n';
}


