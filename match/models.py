from django.db import models
from shared.models import Squad, Columnist
import django.utils.timezone


class Opponent(models.Model):
    name = models.CharField(max_length=255)
    country = models.CharField(max_length=255, default="Ireland")

    def __str__(self):
        return self.name


class Competition(models.Model):
    title = models.CharField(max_length=255)

    def __str__(self):
        return self.title


class Match(models.Model):
    class MatchVenue(models.TextChoices):
        home = "home"
        away = "away"
        neutral = "neutral"

    opponents = models.ForeignKey(Opponent, on_delete=models.PROTECT)
    venue = models.CharField(choices=MatchVenue.choices, max_length=7)
    our_score = models.SmallIntegerField(null=True)
    opp_score = models.SmallIntegerField(null=True)
    date = models.DateField(default=django.utils.timezone.now().date())
    competition = models.ForeignKey(Competition, on_delete=models.PROTECT)
    season = models.CharField(max_length=7)
    squad = models.ForeignKey(Squad, on_delete=models.PROTECT)

    def win(self):
        if self.our_score > self.opp_score:
            return True
        else:
            return False

    def lose(self):
        if self.our_score < self.opp_score:
            return True
        else:
            return False

    def draw(self):
        if self.our_score == self.opp_score:
            return True
        else:
            return False

    def __str__(self):
        return f"{str(self.date)} {str(self.opponents)}, {str(self.season)}, {str(self.competition)}"


class Report(models.Model):
    game = models.ForeignKey(Match, on_delete=models.PROTECT)
    columnist = models.ForeignKey(Columnist, on_delete=models.PROTECT)
    body = models.TextField()



