#include <Eigen/QR>
#include <iostream>

void printArray(const Eigen::MatrixXd &m)
{
  for (int i = 0; i < m.cols(); i++)
  {
    for (int j = 0; j < m.rows(); j++)
    {
      std::cout << m(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

int main(void)
{
  Eigen::MatrixXd m(2, 2);
  m(0, 0) = 3.0;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = 4;

  auto pinv = m.completeOrthogonalDecomposition().pseudoInverse();

  printArray(m);
  printArray(pinv);
  return 0;
}
