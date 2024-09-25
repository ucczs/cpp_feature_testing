# Floating values distribution

Count the values which are actually possible with a floating value:
* increment an integer value from 0 to max(int)
* in every increment reinterpret the integer value as a floating value
* check the value of the new float and group it

```
mini    (0.0    <-> 1):
1065353216      (=0.496094)
middle  (1      <-> 1e+18):
501091179       (=0.233339)
big     (1e+18  <-> 3.40282e+38):
572650644       (=0.266661)
nan:
8388608         (=0.00390625)
```

# Result

* almost half of all floating values are in between 0.f and 1.f
* a quarter of all floating values are in between 1.f and 1e+18
* a quarter of all floating values are in between 1e+18 and 3.4e+38