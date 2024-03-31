# 2024 FLINT development workshop in Bordeaux

## Photos

![workshop1](https://github.com/flintlib/flintlib.github.io/assets/368838/37c1cdd3-269e-4663-8fae-cc0fdd4487d7)
![workshop2](https://github.com/flintlib/flintlib.github.io/assets/368838/a9aa5d20-fd47-4895-9add-05f7e8adeeeb)
![workshop3](https://github.com/flintlib/flintlib.github.io/assets/368838/6079702b-461d-41da-87e4-053951ba0953)

## Report

Edgar Costa:

* fixed flints formula in homebrew https://github.com/Homebrew/homebrew-core/pull/166490
* improved the release CI, to have hashes and nightly releases
* helped Bill with his Jupiter kernel development using xeus
* parsed the headers and the documentation with pycparser, so one can find mismatches, and fix them accordingly
* I still hope to submit a couple of PRs where I plan:
  * fix mismatches between types and argument names
  * have a CI that checks that new added functions are documented

Hartmut Monien:

- Examples for roots of ZZ[x] in Z[p]
- Examples for tanh-sinh integration
- Example for “Monien” summation
- Implementation of Flint general rings in Haskell version
- Permutations in Flint

Marc Mezzarobba:

* Worked on basic Sage wrappers for FLINT generics, https://github.com/mezzarobba/flint_gr_sage
* Took part in random discussions, including about API design for ODEs and holonomic functions, https://github.com/flintlib/flint/issues/1881

Albin Ahlbäck:

- Fixed some build issues (disabling static build by default, removed `ldconfig` from Make, etc.), which led to a new patch for FLINT (v3.1.2) as Andreas Enge could not build with `ldconfig`.
- Extended and corrected `config.guess`, and made changes accordingly in `configure.ac`.
- Worked out some sloppy lower bound for high multiplication and squaring routines.
- Fixed warnings in the "base" modules when setting `-Wextra` (mostly signed-unsigned compares and unused variables where the problem). Also created a new CI runner for checking for regressions here.
- Fixed wrong stack usage for assembly routines.
- Created some hardcoded assembly routines for low multiplication. This has not been merged yet as I'm currently trying to figure out whether we actually need $n + 1$ limbs, or simply $n$ limbs would suffice.
- Worked with AVX512 for `fft_small` a bit, and tried to see where we could optimize this module. Let's see if I continue with this one, but I think it is named `fft_small_assembly` in my repository if anyone would like to check it out.
- Had a great time and met new people :sunglasses:

Jean Kieffer:

My main focus was to improve the performance of `acb_theta` functions by avoiding unnecessary computations as much as possible (I figured it would be a good idea to clean this up before thinking about thresholds with `acb_modular_theta`):
- I introduced a "context" structure to avoid recomputing things multiple times in the quasilinear algorithm (e.g. computing Cholesky decompositions and exponentials of the input values only once.)
- Started rewriting key internal functions in the module (`acb_theta_naive_worker`, `acb_theta_ql_steps`) to use this new structure.
- Thought about more efficient ways to handle error bounds in the module, e.g. some internal functions should ignore the error radii of their inputs.
- All this didn't converge during the three days, but I'll continue working on it and hope to make a PR before the next workshop.
- I second "had a great time and met new people"!

Ricardo Buring:

- Discussed with Fredrik and Marc about an [API for D-finite functions and ODEs in FLINT](https://github.com/flintlib/flint/issues/1881).
- Worked on [generic implementations of Newton iteration and divide-and-conquer](https://gitlab.inria.fr/ricardo-thomas.buring/d-finite-fun) to solve systems of linear ODEs with univariate polynomial coefficients. After some more testing/fixing and small API changes, I'll be making PRs for including these in the `gr_poly` module, hopefully in the near future.
- Discussed some potential optimizations of the above, e.g. using polynomials with matrix coefficients and passing an evaluation point directly. Also started benchmarking the above implementations.
- Two [minor](https://github.com/flintlib/flint/pull/1859) [documentation](https://github.com/flintlib/flint/pull/1860) PRs.
- Briefly looked at trying to [build the documentation faster](https://sagemath.zulipchat.com/#narrow/stream/408539-flint/topic/building.20the.20docs.20faster)
- Made an [amusing logo](https://sagemath.zulipchat.com/#narrow/stream/408539-flint/topic/logo/near/427644504).

Vincent Neiger:

Hello, small report (on my remote participation):
besides a bug fix on n_primitive_root, I have been working on a small prime FFT (prime up to ~60 bits, not using floating point conversions). Initially this was with nmod_poly_mat multiplication in mind, but in the end I thought it was good to understand better the FFT for nmod_poly first, and then move to the matrix case. I still need some more time (e.g. only forward FFT is done until now, and with no TFT) and then I should also do some more testing. But my current code is relatively concise and matches the performance of NTL's forward FFT. It also seems competitive with the current fft_small, if not faster, which surprises me: I would very much welcome any help on a good benchmarking file for fft_small's forward DFT for various sizes (not counting the time for precomputing root tables).

Bill Allombert:

- Did some benchmarking of FLINT vs Pari/GP, identified factoring and L-function bottlenecks

Kartik Venkatram

- Nearly finished PR for [sparse linear algebra](https://github.com/flintlib/flint/pull/1845)

Oscar Benjamin

- Building python-flint [using meson](https://github.com/flintlib/python-flint/pull/129)

Fredrik Johansson

- Fixed several generics issues reported by participants
- Refactored the generic power series code
- Optimized `flint_mpn_mulmod_preinvn` and related functions using mulhigh
- Implemented generic C mulhigh
- Started working on optimized ``mpn_mod`` code

## When and where

* March 18 - 22, 2024
* University of Bordeaux, Bordeaux, France
* We have booked rooms 74 and 73 (ground floor) at LaBRI for the whole week ([how to get to LaBRI](https://www.labri.fr/en/presentation/coming-labri))

![location](https://github.com/flintlib/flintlib.github.io/assets/368838/a2469343-f13b-4cf0-823d-a9d48fdcad0e)

## Schedule

* 9:30 Monday morning - 17:00 Friday afternoon (but feel free to come only for a part of the week)
* Thursday 10:00-12:00 we will co-host the usual weekly [Bordeaux SageMath meeting](https://wiki.sagemath.org/thursdaysbdx)

## Discussion

* Zulip chat: [https://sagemath.zulipchat.com/#narrow/stream/408539-flint](https://sagemath.zulipchat.com/#narrow/stream/408539-flint)
* Wiki: [https://github.com/flintlib/flint/wiki/Workshop-2024](https://github.com/flintlib/flint/wiki/Workshop-2024)

## Planned projects

* Performance tuning
* Integration in other software (SageMath, Oscar, python-flint, SymPy, etc.)
* Numerical and exact linear algebra
* p-adic arithmetic
* Generics
* Theta functions
* Noncommutative polynomials

## Organizers

* Fredrik Johansson (<fredrik.johansson@gmail.com>)
* Sébastien Labbé (<sebastien.labbe@labri.fr>)
* Andreas Enge (<andreas.enge@inria.fr>)
* Joëlle Lacoste-Rodrigues (admin)

## Registration

To register for the workshop, please contact Fredrik. We expect to have funds to cover local expenses and/or travel for some participants, but we are still waiting for confirmation about the budget. Remote participation will be possible.

## Participants

* Albin Ahlbäck
* Bill Allombert
* Oscar Benjamin (Tuesday - Thursday)
* Alex Best (tentatively, remote only)
* Ricardo Buring
* Xavier Caruso (tentatively, part of the week)
* Edgar Costa
* Vincent Delecroix
* Andreas Enge (except for Thursday)
* Fredrik Johansson
* Jean Kieffer (Tuesday - Thursday)
* Sébastien Labbé (Thursday)
* Marc Mezzarobba
* Hartmut Monien
* Vincent Neiger (remote, maybe in person)
* Aurel Page (Thursday morning)
* Julian Rüth (remote)
* Éric Schost (remote)
* Kartik Venkatram

## Funding

* [ANR NuSCAP](https://nuscap.gitlabpages.inria.fr/index.html)
