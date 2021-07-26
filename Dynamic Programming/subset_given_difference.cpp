/** We are given a sum, d and we need to count the no. of ways 
 * such that diff between s1 and s2 is d, abs(s1-s2) = d,
 * let s1 > s2, then
 * s1 - s2 = diff
 * s1 + s2 = sum
 * s1 = (diff+sum)/2 **/

/** Now all we have to do is just see the no. of ways of attaining s1 from the
  * array, we can just use a subset sum function to do this **/