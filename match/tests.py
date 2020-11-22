from django.test import TestCase
from .models import Competition, Match, Opponent, Report
from shared.models import Squad, Columnist
from datetime import date


class CompetitionTestCase(TestCase):
    def test_string(self):
        competition = Competition.objects.create(
            title="FAI Cup"
        )
        self.assertEqual(str(competition), "FAI Cup")


class MatchTestCase(TestCase):
    def setUp(self):
        self.competition = Competition.objects.create(
            title="FAI Cup"
        )
        self.opponents = Opponent.objects.create(
            name="Finn Harps"
        )
        self.squad = Squad.objects.create(
            name="First Team"
        )

    def test_match(self):
        match = Match.objects.create(
            opponents = self.opponents,
            venue = "neutral",
            our_score = 2,
            opp_score = 1,
            date = date(1999, 5, 10),
            competition = self.competition,
            season = "1998/99",
            squad = self.squad
        )

        self.assertEqual(match.season, "1998/99")
        self.assertEqual(str(match.squad), "First Team")
        self.assertTrue(match.win())
        self.assertFalse(match.lose() or match.draw())
        self.assertEqual(str(match), "1999-05-10 Finn Harps, 1998/99, FAI Cup")


