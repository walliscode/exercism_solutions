namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };

enum class Action { read, write, remove };

bool display_post(const AccountStatus &poster, const AccountStatus &viewer) {
  bool can_view{true};

  switch (poster) {
  case (AccountStatus::troll): {
    if (poster != viewer) {
      can_view = false;
    }
    break;
  }
  default:
    break;
  }
  return can_view;
}
bool permission_check(const Action &action,
                      const AccountStatus &account_status) {

  bool permission_granted{false};
  switch (account_status) {
  case (AccountStatus::mod): {
    permission_granted = true;
    break;
  }
  case (AccountStatus::guest): {
    if (action == Action::read) {
      permission_granted = true;
    }
    break;
  }
  case (AccountStatus::user): {
    if ((action == Action::read) || (action == Action::write)) {
      permission_granted = true;
    }
    break;
  }
  case (AccountStatus::troll): {
    if ((action == Action::read) || (action == Action::write)) {
      permission_granted = true;
    }
    break;
  }
  default:
    break;
  }
  return permission_granted;
}

bool valid_player_combination(const AccountStatus &player_1,
                              const AccountStatus &player_2) {

  bool can_play{true};

  if (player_1 == AccountStatus::guest || player_2 == AccountStatus::guest) {
    can_play = false;
  }

  if (player_1 == AccountStatus::troll || player_2 == AccountStatus::troll) {
    can_play = false;
    if (player_1 == player_2) {
      can_play = true;
    }
  }

  return can_play;
}

bool has_priority(const AccountStatus &acc_1, const AccountStatus &acc_2) {
  bool priority{false};

  switch (acc_1) {
  case (AccountStatus::mod): {
    priority = true;
    if (acc_2 == AccountStatus::mod) {
      priority = false;
    }
    break;
  }
  case (AccountStatus::user): {
    if (acc_2 == AccountStatus::guest || acc_2 == AccountStatus::troll) {
      priority = true;
    }
    break;
  }
  case (AccountStatus::guest): {
    if (acc_2 == AccountStatus::troll) {
      priority = true;
    }
    break;
  }
  case (AccountStatus::troll): {
    priority = false;
  } break;
  default:
    break;
  }

  return priority;
}

} // namespace hellmath
