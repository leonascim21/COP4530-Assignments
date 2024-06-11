#include <utility>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

template<typename T>
class heap_pq
{
public:
  heap_pq()
  {
    heap_ptr = 1;
    heap.push_back(T());
  }

  const T& findMax( )
  {
    return heap[1];
  }

  void insert( const T& x )
  {
    heap_ptr++;

    if(heap_ptr < heap.size())
      heap[heap_ptr] = x;
    else
      heap.push_back(x);
    heap_property_up(heap_ptr);

  }

  void remove( )
  {
    swap(heap[1], heap[--heap_ptr]);
    heap_property_down(1);
    heap.pop_back();
  }

  void print( )
  {
    for (uint32_t i = 0; i < heap_ptr; i++)
      cout << i << ":" << heap[i] << "\n";
  }

  void property_validate()
  {
    for(int i = 2; i < heap_ptr; i++)
    {
      if(heap[i] > heap[i/2])
      {
        cout << "Heap property violations found." << endl;
        return;
      }
    }
    cout << "No heap property violations found." << endl;

  }

  void reserve(uint32_t size)
  {
    heap.reserve(size + 1);
  }

  uint32_t quantity()
  {
    return heap_ptr-1;
  }

private:

  vector<T> heap;
  uint32_t heap_ptr;

  T& heap_findMax()
  {
    /* YOUR CODE GOES HERE */
  }

  void heap_insert ( const T& x )
  {
    /* YOUR CODE GOES HERE */
  }

  void heap_remove ( )
  {
    /* YOUR CODE GOES HERE */
  }

  void heap_print( )
  {
    /* YOUR CODE GOES HERE */
  }

  void heap_property_validate()
  {
    /* YOUR CODE GOES HERE */
  }

  void heap_reserve(uint32_t size)
  {
    /* YOUR CODE GOES HERE */
  }

  uint32_t heap_quantity()
  {
    /* YOUR CODE GOES HERE */
  }


  //  ----------------------
  //
  //  Helper functions
  //
  //

  void heap_property_up(uint32_t item)
  {
    while(item > 1 && heap[item] > heap[item/2])
    {
      swap(heap[item], heap[item/2]);
      item /= 2;
    }
  }

  void heap_property_down(T item)
  {
    int child;
    while(2 * item < heap_ptr)
    {
      child = 2 * item;
      if(child != heap_ptr - 1 && (heap[child] < heap[child+1]))
      {
        child++;
      }

      if(heap[item] >= heap[child])
        break;

      swap(heap[item], heap[child]);
      item = child;

    }
  }
};


int main()
{
  heap_pq<int> h;
  uint32_t val;
  char op;

  h.reserve(128);

  while(cin >> op >> val )
  {
    cout << "Op = " << op << ", val = " << val << "\n";
    if(op == 'E')
    {
      h.insert(val);
      cout << "Max = " << h.findMax() << "\n";
    }
    if(op == 'D')
    {
      if(val == 0)
      {
        h.remove();
        val = h.quantity();
      }
      while(val)
      {
        h.remove();
        val--;
      }
    }
    h.print();
    h.property_validate();
  }
}
