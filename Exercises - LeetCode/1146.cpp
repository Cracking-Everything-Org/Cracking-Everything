class SnapshotArray {
public:
    unordered_map<int, map<int, int>> snapshots;
    int cur_snap = 0;

    SnapshotArray(int length) {
        cur_snap = 0;
    }

    void set(int index, int val) {
        snapshots[index][cur_snap] = val;
    }

    int snap() {
        return cur_snap++;
    }

    int get(int index, int snap_id) {
        auto it = snapshots[index].upper_bound(snap_id);
        return it == begin(snapshots[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
