.pragma library

var initText = "\n\
\n\
Inductive nat : Type :=\n\
  | O : nat\n\
  | S : nat → nat.\n\
\n\
Fixpoint plus (n : nat) (m : nat) : nat :=\n\
  match n with\n\
    | O ⇒ m\n\
    | S n' ⇒ S (plus n' m)\n\
  end.\n\
\n\
Notation \"x + y\" := (plus x y)\n\
                       (at level 50, left associativity)\n\
                       : nat_scope.\n\
\n\
Theorem plus_O_n : ∀n : nat, 0 + n = n.\n\
Proof.\n\
  intros n. reflexivity. Qed.\n\
\n\
";

