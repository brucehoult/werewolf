module: werewolf
synopsis: calculate villager's probability of winning in different sized groups
author: Bruce Hoult
copyright: creative commons

define constant <activity>
  = one-of(werewolves-kill:, seer-asks:, villagers-lynch:);

define constant <num-people> = <integer>;
define constant <probability> = <double-float>;
define constant <fp> = <double-float>;

// define sealed class <state> (<object>)
//     slot activity :: <activity> = werewolves-kill:, init-keyword: activity:;
//     slot num-werewolves :: <num-people>, required-init-keyword: werewolves:;
//     slot num-villagers :: <num-people>, required-init-keyword: villagers:;
//     slot seer-lives? :: <boolean>, required-init-keyword: seer:;
//     slot seer-villagers-confirmed :: <num-people> = 0, init-keyword: villagers-confirmed:;
//     slot seer-wolves-confirmed :: <num-people> = 0, init-keyword: wolves-confirmed:;
//     //slot villagers-win-probability :: <probability>, required-init-keyword: probability:;
// end <state>;

// define sealed domain make(singleton(<state>));
// define sealed domain initialize(<state>);

// define sealed class <state-table> (<table>) end;

// define method table-protocol (table :: <state-table>)
//  => (test-function :: <function>,
//      hash-function :: <function>);
//   values(method (a :: <state>, b :: <state>) => (equiv :: <boolean>);
//            a.activity == b.activity &
//            a.num-werewolves == b.num-werewolves &
//            a.num-villagers == b.num-villagers &
//            a.seer-lives? == b.seer-lives? &
//            a.seer-villagers-confirmed == b.seer-villagers-confirmed &
//            a.seer-wolves-confirmed == b.seer-wolves-confirmed;
//          end,
//          method (a :: <state>) => (id :: <num-people>, state :: <num-people>);
//            let (id, state) = object-hash(a.activity, #f);
//            local method merge(o :: <object>)
//                    let (o-id, new-state) = object-hash(o, state);
//                    id := merge-hash-ids(id, o-id, ordered: #t);
//                    state := new-state;
//                  end;
//            merge(a.num-werewolves);
//            merge(a.num-villagers);
//            merge(a.seer-lives?);
//            merge(a.seer-villagers-confirmed);
//            merge(a.seer-wolves-confirmed);
//            values(id, state);
//          end);
// end method table-protocol; 


define function win-probability
    (#key activity :: <activity>,
     werewolves :: <num-people>,
     villagers :: <num-people>,
     seer-lives? :: <boolean> = #f,
     villagers-confirmed :: <num-people> = 0,
     wolves-confirmed :: <num-people> = 0)
 => (prob :: <probability>);
  format-out("%= w=%d, v=%d, seer=%=, sv=%d, sw=%d\n",
             activity, werewolves, villagers,
             seer-lives?, villagers-confirmed, wolves-confirmed);
  let prob =
    case
      werewolves == 0 => 1.0;
      villagers < werewolves => 0.0;
      otherwise =>
        select (activity)
          werewolves-kill: =>
            if (seer-lives?)
              let prob-seer-killed = 1.0 / villagers;
              let prob-confirmed-villager-killed = as(<fp>, villagers-confirmed) / as(<fp>, villagers);
              let prob-unconfirmed-villager-killed = 1.0 - prob-seer-killed - prob-confirmed-villager-killed;
              prob-seer-killed *
                win-probability(activity: villagers-lynch:,
                                werewolves: werewolves,
                                villagers: villagers - 1) +
                prob-confirmed-villager-killed *
                win-probability(activity: villagers-lynch:,
                                werewolves: werewolves,
                                villagers: villagers - 1,
                                seer-lives?: #t,
                                villagers-confirmed: villagers-confirmed - 1,
                                wolves-confirmed: wolves-confirmed) +
                prob-unconfirmed-villager-killed *
                win-probability(activity: villagers-lynch:,
                                werewolves: werewolves,
                                villagers: villagers - 1,
                                seer-lives?: #t,
                                villagers-confirmed: villagers-confirmed,
                                wolves-confirmed: wolves-confirmed)
            else
              win-probability(activity: villagers-lynch:,
                              werewolves: werewolves,
                              villagers: villagers - 1)
            end;

          seer-asks: =>
            if (seer-lives?)
              let total-unknown = as(<fp>, werewolves + villagers - wolves-confirmed - villagers-confirmed - 1);
              let prob-villager-confirmed = as(<fp>, villagers - villagers-confirmed) / total-unknown;
              let prob-werewolf-confirmed = as(<fp>, werewolves - wolves-confirmed) / total-unknown;
              prob-villager-confirmed *
                win-probability(activity: werewolves-kill:,
                                werewolves: werewolves,
                                villagers: villagers,
                                seer-lives?: #t,
                                villagers-confirmed: villagers-confirmed + 1,
                                wolves-confirmed: wolves-confirmed) +
                prob-werewolf-confirmed *
                win-probability(activity: werewolves-kill:,
                                werewolves: werewolves,
                                villagers: villagers,
                                seer-lives?: #t,
                                villagers-confirmed: villagers-confirmed,
                                wolves-confirmed: wolves-confirmed + 1)
            else
              win-probability(activity: werewolves-kill:,
                              werewolves: werewolves,
                              villagers: villagers)
            end;

          villagers-lynch: =>
            if (werewolves == villagers)
              0.0;
            elseif (wolves-confirmed == 2)
              1.0;
            elseif (#f & even?(werewolves - villagers))
              // bad news to lynch anyone!!!
              win-probability(activity: seer-asks:,
                              werewolves: werewolves,
                              villagers: villagers,
                              seer-lives?: seer-lives?,
                              villagers-confirmed: villagers-confirmed,
                              wolves-confirmed: wolves-confirmed)
            else
              let total-people = as(<fp>, werewolves + villagers);
              let prob-confirmed-wolf-killed =
                as(<fp>, wolves-confirmed) / total-people;
              let prob-unconfirmed-wolf-killed =
                as(<fp>, werewolves - wolves-confirmed) / total-people;
              let prob-seer-killed = if (seer-lives?) 1.0 / total-people else 0.0 end;
              let prob-confirmed-villager-killed =
                as(<fp>, villagers-confirmed) / total-people;
              let prob-unconfirmed-villager-killed =
                as(<fp>, villagers - villagers-confirmed) / total-people - prob-seer-killed;
              prob-confirmed-wolf-killed *
                win-probability(activity: seer-asks:,
                                werewolves: werewolves - 1,
                                villagers: villagers,
                                seer-lives?: seer-lives?,
                                villagers-confirmed: villagers-confirmed,
                                wolves-confirmed: wolves-confirmed - 1) +
                prob-unconfirmed-wolf-killed *
                win-probability(activity: seer-asks:,
                                werewolves: werewolves - 1,
                                villagers: villagers,
                                seer-lives?: seer-lives?,
                                villagers-confirmed: villagers-confirmed,
                                wolves-confirmed: wolves-confirmed) +
                prob-seer-killed *
                win-probability(activity: seer-asks:,
                                werewolves: werewolves,
                                villagers: villagers - 1) +
                prob-confirmed-villager-killed *
                win-probability(activity: seer-asks:,
                                werewolves: werewolves,
                                villagers: villagers - 1,
                                seer-lives?: seer-lives?,
                                villagers-confirmed: villagers-confirmed - 1,
                                wolves-confirmed: wolves-confirmed) +
                prob-unconfirmed-villager-killed *
                win-probability(activity: seer-asks:,
                                werewolves: werewolves,
                                villagers: villagers - 1,
                                seer-lives?: seer-lives?,
                                villagers-confirmed: villagers-confirmed,
                                wolves-confirmed: wolves-confirmed)
            end if;
        end select;
    end case;
  prob;
end win-probability;


define function main(name, arguments)
  for (i from 2 to 100)
    let prob = win-probability(activity: werewolves-kill:,
                               werewolves: 2,
                               villagers: i,
                               seer-lives?: #f);
    format-out("%d: %=\n", i + 2 + 1, prob);
    force-output(*standard-output*);
  end;
  exit-application(0);
end function main;

main(application-name(), application-arguments());
