#include <vector>
#include <string>

class Tvar {
public:
  Tvar() {};
  virtual ~Tvar() {};
  virtual float obvod() = 0;
  virtual float obsah() = 0;
  virtual std::string jmeno() = 0;
};

// class Kruh odvozena z tvaru

// class Ctverec odvozena z tvaru
// pripadne class polygon a odvodit tridu ctverec

// zkuste kod rozdelit do vice souboru!

int main()
{

   return 0;
};
