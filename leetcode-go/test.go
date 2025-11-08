package main

type LazySegmentTree struct {
	ones []int
	lazy []bool
	n    int
}

func (st *LazySegmentTree) maintain(o int) {
	st.ones[o] = st.ones[2*o] + st.ones[2*o+1]
}

func (st *LazySegmentTree) pushDown(o, l, r int) {
	if st.lazy[o] {
		mid := (l + r) / 2
		// 翻转左子树
		st.ones[2*o] = (mid - l + 1) - st.ones[2*o]
		st.lazy[2*o] = !st.lazy[2*o]
		// 翻转右子树
		st.ones[2*o+1] = (r - mid) - st.ones[2*o+1]
		st.lazy[2*o+1] = !st.lazy[2*o+1]
		st.lazy[o] = false
	}
}

func (st *LazySegmentTree) build(o, l, r int, nums []int) {
	if l == r {
		st.ones[o] = nums[l]
		return
	}
	mid := (l + r) / 2
	st.build(2*o, l, mid, nums)
	st.build(2*o+1, mid+1, r, nums)
	st.maintain(o)
}

func (st *LazySegmentTree) update(o, l, r, ql, qr int) {
	if ql <= l && r <= qr {
		st.ones[o] = (r - l + 1) - st.ones[o]
		st.lazy[o] = !st.lazy[o]
		return
	}
	st.pushDown(o, l, r)
	mid := (l + r) / 2
	if ql <= mid {
		st.update(2*o, l, mid, ql, qr)
	}
	if qr > mid {
		st.update(2*o+1, mid+1, r, ql, qr)
	}
	st.maintain(o)
}

func (st *LazySegmentTree) query(o, l, r, ql, qr int) int {
	if ql <= l && r <= qr {
		return st.ones[o]
	}
	st.pushDown(o, l, r)
	mid := (l + r) / 2
	res := 0
	if ql <= mid {
		res += st.query(2*o, l, mid, ql, qr)
	}
	if qr > mid {
		res += st.query(2*o+1, mid+1, r, ql, qr)
	}
	return res
}

func handleQuery(nums1 []int, nums2 []int, queries [][]int) []int64 {
	n := len(nums1)
	tree := &LazySegmentTree{
		ones: make([]int, 4*n),
		lazy: make([]bool, 4*n),
		n:    n,
	}
	tree.build(1, 0, n-1, nums1)

	var sum int64
	for _, v := range nums2 {
		sum += int64(v)
	}

	ans := []int64{}
	for _, q := range queries {
		if q[0] == 1 {
			tree.update(1, 0, n-1, q[1], q[2])
		} else if q[0] == 2 {
			ones := tree.query(1, 0, n-1, 0, n-1)
			sum += int64(ones) * int64(q[1])
		} else {
			ans = append(ans, sum)
		}
	}
	return ans
}
