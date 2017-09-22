#include <vector>
using namespace std;
struct data{
  vector<int> taple;
  double key;
};
struct HEAP{
  unsigned int length;
  unsigned int heap_size;
  data **A;
};
void HEAPIFY(HEAP *H, int i);
void HEAPIFY2(HEAP *H, int i);
void BUILD_HEAP(HEAP *H, int n, data **A, int length);
void HEAPSORT(int n, data **A);
data* EXTRACT_MAX(HEAP *H) ;
void DOUBLE_HEAPSIZE(HEAP *H);
void INSERT(HEAP *H, data *node) ;
void DELETE(HEAP *H, int i);

