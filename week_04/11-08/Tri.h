#ifndef TRI_H_
#define TRI_H_
using namespace std;

class Tri {
public:
  Tri(unsigned int length_input);
  void draw_triangle();
private:
  unsigned int counter;
  unsigned int length;
};

#endif /* TRI_H_ */
