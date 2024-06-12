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
    return heap_findMax();
  }

  void insert( const T& x )
  {
    heap_insert(x);
  }

  void remove( )
  {
    heap_remove();
  }

  void print( )
  {
    heap_print();
  }

  void property_validate()
  {
    heap_property_validate();
  }

  void reserve(uint32_t size)
  {
    heap_reserve(size);
  }

  uint32_t quantity()
  {
    return heap_quantity();
  }

private:

  vector<T> heap;
  uint32_t heap_ptr;

  T& heap_findMax()
  {
    return heap[1];
  }

  void heap_insert ( const T& x )
  {
    if(heap_ptr < heap.size())
      heap[heap_ptr] = x;
    else
      heap.push_back(x);

    heap_property_up(heap_ptr);
    heap_ptr++;


  }

  void heap_remove ( )
  {
    if(heap_ptr <= 1)
      return;

    heap_ptr--;
    swap(heap[1], heap[heap_ptr]);
    heap_property_down(1);
  }

  void heap_print( )
  {
    cout << "Heap\n";
    for (int i = 0; i < heap_ptr; i++)
      cout << i << ": " << heap[i] << "\n";
  }

  void heap_property_validate()
  {
    bool valid = true;

    for (int i = 1; i < heap_ptr/2; i++)
    {
      if(heap[i] < heap[i*2] && heap[i] < heap[i*2+1])
      {
        valid = false;
        break;
      }
    }

    if(valid)
      cout << "No heap property violations found.\n\n";
    else
      cout << "Heap property violations found.\n\n";

  }

  void heap_reserve(uint32_t size)
  {
    if (size > heap_ptr)
      heap.resize(size, 0);
  }

  uint32_t heap_quantity()
  {
    return heap_ptr-1;
  }


  //  ----------------------
  //
  //  Helper functions
  //
  //

  void heap_property_up(uint32_t item)
  {
    if(heap[item] < heap[item / 2] || item <= 1)
      return;
    else
      swap(heap[item], heap[item / 2]);

    item/=2;

    (heap_property_up(item));

  }

  void heap_property_down(T item)
  {
    if(item * 2 >= heap_ptr)
      return;

    int child = 2 * item;

    if(heap[child+1] > heap[child] && (child + 1 < heap_ptr) )
      ++child;

    if(heap[item] > heap[child])
      return;

    swap(heap[item], heap[child]);
    item = child;

    heap_property_down(item);

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
