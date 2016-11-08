#ifndef CAR_H_
#define CAR_H_
#include <string>
using namespace std;

class Car {
  public:
    Car(int km_in, string type_in);
    void run(int km_run);
    int get_km();
  private:
    int km;
    string type;
};

#endif /* CAR_H_ */
