// slidetest.cc

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/rolling_count.hpp>
#include <boost/accumulators/statistics/rolling_sum.hpp>
#include <boost/accumulators/statistics/stats.hpp>

#include <iostream>

//using boost::accumulators::accumulator_set;
//using boost::accumulators::stats;
using namespace boost::accumulators;
using std::cout;
using std::endl;


int
main (int argc, char* argv[])
{
  accumulator_set<int, stats<tag::rolling_sum> > acc(tag::rolling_window::window_size = 3);

  acc(1);
  acc(2);
  acc(3);
  acc(4);

  cout << "rolling sum: " << rolling_sum(acc) << " (should be 9)\n";

  return 0;
}
