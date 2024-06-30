#include <utility>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

template<typename T>
class quicksort
{
public:
  uint32_t next;         // points at next available node

  quicksort( )
  {
    next = 0;
  }

  void insert( const T & x )
  {
      quicksort_insert(x);
  }

  void print( )
  {
    quicksort_print();
  }

  void reserve(uint32_t size)
  {
    quicksort_reserve(size);
  }

  uint32_t quantity()
  {
    return quicksort_quantity();
  }

  void sort()
  {
    if (q.size() > 1)
    {
      quicksort_sort(0, q.size()-1);
    }
  }

private:

  vector<T> q;

  void quicksort_insert ( const T & x )
  {
    q.push_back(x);
  }


  void quicksort_print( )
  {
    int i = 0;
    cout <<"List\n";
    for(T item : q)
    {
      cout << i++ << ": " << item << endl;
    }
  }


  void quicksort_reserve(uint32_t size)
  {
    q.reserve(size);
  }

  uint32_t quicksort_quantity()
  {
      return q.size();
  }

  void quicksort_sort(uint32_t start, uint32_t end)
  {
    if(start < end)
    {
      uint32_t pivotIndex = partition(start, end);
      if (pivotIndex > 0)
        quicksort_sort(start, pivotIndex-1);
      quicksort_sort(pivotIndex+1, end);
    }
  }

  //  ----------------------
  //
  //  Helper functions
  //
  //


  // Returns the pivot point's index

  uint32_t partition(uint32_t start, uint32_t end)
  {
    T pivot = q[end];

    uint32_t i = start;

    for(uint32_t j = start; j < end; j++)
    {
      if(q[j] < pivot)
        swap(q[j], q[i++]);
    }

    swap(q[i], q[end]);
    return i;
  }

};


int main()
{
  quicksort<int> q;
  uint32_t val;

  q.reserve(1028);

  while(cin >> val )
  {
    q.insert(val);
  }

  q.sort();
  q.print();
}
