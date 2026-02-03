#!/bin/bash

while IFS= read -r line
do
    echo "Testing: $line"
    ./Conversion "$line"
    echo "---"
done << 'EOF'
0
98
98.0
98.0f
-98
-98.0f
-98.9f
98.9f
nan
-inf
+inf
___________________
 0
98.00f
1 0
""
a
aa
aaa
a0
0a
00a
.f
f
0.f
98
98f
98g
98.
98.f
98.g
98..0
98..0f
98.98f
98.0f980f
98.0f.98
98.0f98f
98.0g
98.0f.
-
-98f
-98g
-98.
-98.f
-98.g
-98.99f
-98.42.0f
-98.0f.
-.98.0f
98-98.0f
-98.0g
.
2147483745
-4294967199
EOF