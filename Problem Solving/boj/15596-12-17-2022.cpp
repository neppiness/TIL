long long sum(std::vector<int> &a) {
  long long s = 0;
  for(int x : a) s += x;
  return s;
}