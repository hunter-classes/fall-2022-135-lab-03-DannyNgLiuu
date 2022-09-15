// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::cout << "\n";
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons \n";

  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons \n \n";
  std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons \n \n";

  std::cout << compare_basins("01/01/2018") << "\n";
  std::cout << compare_basins("09/13/2018") << "\n";
  std::cout << compare_basins("11/03/2018") << "\n \n";

  reverse_order("05/29/2018", "06/02/2018");
  std::cout << "\n";
  reverse_order("05/02/2018", "07/22/2018");
  std::cout << "\n";
  return 0;
}
