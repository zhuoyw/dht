#ifndef _DEBRUIN_H_
#define _DEBRUIN_H_

// N.G. de Bruijn (http://www.win.tue.nl/~wsdwnb/)

class debruijn : public fingerlike {
  ptr<vnode> myvnode;
  ptr<locationtable> locations;
  chordID myID;  
  chordID mydoubleID;

 public:
  debruijn ();

  void fill_nodelistres (chord_nodelistres *res)
  {
    res->resok->nlist.setsize (0);
  }
  void fill_nodelistresext (chord_nodelistextres *res)
  {
    res->resok->nlist.setsize (0);
  }

  void stabilize();

  bool isstable () { return true; };
  bool continous_stabilizing () { return true; };
  bool backoff_stabilizing () { return false; };
  void do_backoff () { return; };
  void do_continuous () { stabilize (); };
  void finddoublesucc_cb (chordID s, route path, chordstat status);
  chordID debruijnptr (void);

  //fingerlike methods
  chordID closestsucc (const chordID &x);
  chordID closestpred (const chordID &x, vec<chordID> failed);
  chordID closestpred (const chordID &x);

  void init (ptr<vnode> v, ptr<locationtable> locs, chordID ID);
  void print ();
  void stats () { warn << "stats go here\n";};

};

#endif /* _DEBRUIN_H_ */
